#!usr/bin/env python
# -*- coding: utf-8 -*-

import time
import serial
import smbus

import re
import RPi.GPIO as GPIO
import math
import DB
import micropyGPS
from geopy.distance import geodesic
import threading
import os
import subprocess, shlex

I2C_TEMP_ADDR = 0x5C
KNOT = 1.852
SERIAL_DEVIOCE = '/dev/serial0'
POLE_RADIUS = 6356752.314245 					# 極半径
EQUATOR_RADIUS = 6378137.0 						# 赤道半径

METER_ID_TRIP_A = 1001
METER_ID_TRIP_B = 1002
METER_ID_ODO  = 2001

STATUS_ID_TEMP = 1001
STATUS_ID_HUM = 1002
STATUS_ID_WDGT = 1003
STATUS_ID_LEVEL = 1004


# GPIO Setting
GPIO.setmode(GPIO.BCM)
## GPIO input
GPIO_23_1PPS = 23
GPIO_27_BATTERY = 27

logKm = 0





gps = micropyGPS.MicropyGPS(9, 'dd')
def runTemp():
	# i2c
	i2c = smbus.SMBus(1)


	
	try:
		i2c.write_i2c_block_data(I2C_TEMP_ADDR,0x00,[])
	except:
		pass
	
	
	while True:
		try:
			i2c.write_i2c_block_data(I2C_TEMP_ADDR,0x03,[0x00,0x04])
			time.sleep(0.25)
			block = i2c.read_i2c_block_data(I2C_TEMP_ADDR,0,6)
			hum = float(block[2] << 8 | block[3])/10
			temp = float(block[4] << 8 | block[5]) / 10

			wbgt = 0.7 * hum + 0.3 * temp
			level = 0
			if 31 <= wbgt :
				level = 5
			elif 30 <= wbgt and wbgt <= 28:
				level = 4
			elif 27 <= wbgt and wbgt <= 25:
				level = 3
			elif 24 <= wbgt and wbgt <= 21:
				level = 2
			else:
				level = 1


			DB.updateState([(STATUS_ID_TEMP, str(temp))])
			time.sleep(0.02)
			DB.updateState([(STATUS_ID_HUM, str(hum))])
			time.sleep(0.02)
			DB.updateState([(STATUS_ID_WDGT, str(wbgt))])
			time.sleep(0.02)
			DB.updateState([(STATUS_ID_LEVEL, str(level))])
			time.sleep(0.02)
			time.sleep(0.8)
		except Exception as e:
			print(e)
			pass



def main():
	# SQLite 初期設定
	DB.init_DB()
	# シリアル通信設定
	uart = serial.Serial('/dev/ttyUSB0', 9600, timeout=10)
	# gps設定

	tempThread = threading.Thread(target=runTemp, args=())
	tempThread.daemon = True
#	tempThread.start() # スレッドを起動

	# GPIO setop
	GPIO.setup(GPIO_23_1PPS, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.setup(GPIO_27_BATTERY, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.input(GPIO_27_BATTERY)
	time.sleep(0.003)
	log = DB.selectLastLog()

	if(len(log) !=0):
		logLat = log[0][1]
		logLon = log[0][0]


	uart.readline()

	while True:
		try:
			sentence = uart.readline()
			sentenceStr = sentence.decode('utf-8')

			for x in sentenceStr:
				gps.update(x)

			


			if(sentenceStr.startswith("$GNRMC")):

				# print(sentenceStr)
				gnrmc = sentenceStr.split(",")
				#0  ヘッダー
				#1  時刻
				#2  ステータス
				#3  緯度 (lat)
				#4  N/S表記
				#5  経度 (lon)
				#6  E/W表記
				#7  移動速度(knot)
				#8  進行方向
				#9  日付
				#10 地磁気の偏角
				#11 地磁気のE/W表記
				#12 モード
				#13 チェックサム
				if gnrmc[2]=="A":
					dateStr = "{0}/{1}/{2}".format(gps.date[0] + 2000,gps.date[1], gps.date[1])
					hour = gps.timestamp[0] if gps.timestamp[1] < 24 else gps.timestamp[0] - 24
					timeStr = "{0}:{1}:{2}".format(hour,gps.timestamp[1], gps.timestamp[2])

					speed = getTravelSpeed(float(gnrmc[7]))

					if(speed != 0):
						# 移動中
						if(isSpeed(speed)):
							if (log == None):
								logLat = gps.latitude[0]
								logLon = gps.longitude[0]

							logKm = speed
							newStation = (gps.latitude[0], gps.longitude[0])
							logStation = (logLat, logLon)
							lat = gps.latitude[0]
							lon = gps.longitude[0]
							
							# ログ保存
							logLat = gps.latitude[0]
							logLon = gps.longitude[0]

							# 移動距離算出
							movementKm = geodesic(newStation, logStation).km
							print(str(math.floor(movementKm) / 10) + " km/h")
							DB.insertLog([(dateStr, timeStr, speed, lon, lat)])

							# 各メーターに保存
							odoMeter = selectMeter(METER_ID_ODO)
							tripAMeter = selectMeter(METER_ID_TRIP_A)
							tripBMeter = selectMeter(METER_ID_TRIP_B)


						else:
							print("No movement 1")
					else:
						# 0kmの場合
						# 現状何もしない
						print("No movement 2")

					# 0KM END
				# GNRMC STATUS A END
			# GPS IF END
			bat = GPIO.input(GPIO_27_BATTERY)

			if(bat == 0):
				shutdown()
			
		except Exception as e:
			print('Exception:', e)
	# While End
	

		
# Knot(ノット)から時速(km/h)へ変換
def getTravelSpeed(knot):
	return math.floor(knot * KNOT)
# getTravelSpeed End

# 移動速度を計算
def isSpeed(km):
	if km == 0 and logKm == 0:
		return False
	else:
		return True
# isSpeed End


def shutdown():
	args = shlex.split("sudo shutdown -h now")
	ret = subprocess.call(args)
# shutdown end


if __name__ == "__main__":
	main()