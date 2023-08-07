#!usr/bin/env python
# -*- coding: utf-8 -*-

import serial
import micropyGPS
import threading
import time
import RPi.GPIO as GPIO
import math
import DB


######################################################
# TODO
# 1. GPS情報から緯度経度,日時情報を保存しログへ(NMEA)
# 2. 位置情報(緯度経度)と前回実施した緯度経度より
#     移動した距離をオドメータ,トリップメータ
#     として保存
# 3. トリップメータのリセットはGPIO26で行う
# 
# 
######################################################
# 定数
POLE_RADIUS = 6356752.314245 					# 極半径
EQUATOR_RADIUS = 6378137.0 						# 赤道半径
METER_ID_TRIP_A = 1001
METER_ID_TRIP_B = 1002
METER_ID_ODO  = 2001


# GPS情報
gps = micropyGPS.MicropyGPS(9, 'dd')


#トリップメータ関連
tripResetBtn = False
tripResetStartDate = ""

#最終ログ
lastLon = "";
lastLat = "";


# SQLite 初期設定
DB.init_DB()

# GPS情報を読み込む
def runGPS():
	s = serial.Serial('/dev/serial0', 9600, timeout=10)
	s.readline()
	while True:
		sentence = s.readline().decode('utf-8')
		if(sentence[0] != '$'):
			continue

		for x in sentence:
			gps.update(x)

gpsthread = threading.Thread(target=runGPS)
gpsthread.daemon = True
gpsthread.start()




# 緯度経度から距離へ変換
# @return float (km)
def locationToKilometer(lon, lat):
    # 緯度経度をラジアンに変換
    lat_kamata = math.radians(lat[0])
    lon_kamata = math.radians(lon[0])
    lat_yokosukachuo = math.radians(lat[1])
    lon_yokosukachuo = math.radians(lon[1])

    lat_difference = lat_kamata - lat_yokosukachuo       # 緯度差
    lon_difference = lon_kamata - lon_yokosukachuo       # 経度差
    lat_average = (lat_kamata + lat_yokosukachuo) / 2    # 平均緯度

    e2 = (math.pow(equator_radius, 2) - math.pow(pole_radius, 2)) \
            / math.pow(equator_radius, 2)  # 第一離心率^2

    w = math.sqrt(1- e2 * math.pow(math.sin(lat_average), 2))

    m = equator_radius * (1 - e2) / math.pow(w, 3) # 子午線曲率半径

    n = equator_radius / w                         # 卯酉線曲半径

    distance = math.sqrt(math.pow(m * lat_difference, 2) \
                   + math.pow(n * lon_difference * math.cos(lat_average), 2)) # 距離計測

    print(distance / 1000)
    return (distance / 1000)


if __name__ == "__main__":
	while True:
		km = 0.0
		if gps.clean_sentences > 20:
			#GPS情報から日時を取得
			hour = gps.timestamp[0] if gps.timestamp[1] < 24 else gps.timestamp[0] - 24
			dateStr = "{0}/{1}/{2}".format(gps.date[0] + 2000,gps.date[1], gps.date[1])
			timeStr = "{0}:{1}:{2}".format(hour,gps.timestamp[1], gps.timestamp[2])

			# GPS情報から緯度経度を算出
			lat = gps.latitude_string().replace("' N", "").replace("' W", "").replace("°", "")
			lon = gps.longitude_string().replace("' N", "").replace("' W", "").replace("°", "")


			# 最終取得位置から移動距離を算出
			if not (len(lastLat) == 0 and len(lastLon) == 0):
				km = locationToKilometer([lon.replace('°','.').replace('\'',''), lastLon], [lat.replace('°','.').replace('\'',''), lastLat])
			# IF End (len(lastLat))

			print(gps.latitude_string() + "___" + gps.longitude_string())
			# 最終取得位置を更新
			lastLon = float(gps.latitude_string().replace("' N", "").replace("' W", "").replace("°", ""))
			lastLat = float(gps.longitude_string().replace("' N", "").replace("' W", "").replace("°", ""))

			# オドメーター取得
			odoMeterLog = DB.selectMeter(METER_ID_ODO)

			odoResult = float(odoMeterLog[0][0]) + km

			# トリップメータ取得
			tripA_MeterLog = DB.selectMeter(METER_ID_TRIP_A)
			tripA_Result = float(tripA_MeterLog[0][0]) + km
			

			tripB_MeterLog = DB.selectMeter(METER_ID_TRIP_B)
			tripB_Result = float(tripB_MeterLog[0][0]) + km
			# 各情報をDBへ保存
			DB.updateMeter([(odoResult, METER_ID_ODO),(tripA_Result, METER_ID_TRIP_A),(tripB_Result, METER_ID_TRIP_B)])
			DB.insertLog([(dateStr, timeStr, lon, lat)])
			
		# IF End (clean_sentences)
		# GPIO制御

		# I2C制御

		# USB制御