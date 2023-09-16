#!usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

# テーブル作成クエリ
CREATE_LOG = "CREATE TABLE IF NOT EXISTS log('date' TEXT, 'time' TEXT, speed TEXT, lon TEXT, lat TEXT)"
CREATE_METER = "CREATE TABLE IF NOT EXISTS meter(id INT PRIMARY KEY, km TEXT)"
CREATE_GPIO = "CREATE TABLE IF NOT EXISTS gpio(id INT PRIMARY KEY, status INTEGER)"
CREATE_TEMP = "CREATE TABLE IF NOT EXISTS status(id INT PRIMARY KEY, value TEXT)"

# データ挿入
INSERT_LOG = "INSERT INTO log('date', 'time', speed, lon, lat)VALUES(?, ?, ?, ?, ?);"
# GPIO初期ステータス
INSERT_GPIO = "INSERT INTO gpio(id, status)VALUES(?, ?)"

UPDATE_STATE = "INSERT OR REPLACE INTO status (id, value) VALUES (?, ?)"

# データ更新
UPDATE_METER = "UPDATE SET meter=? where id=?"

# データ取得
SELECT_METER = "SELECT km FROM meter WHERE id = {0}"

SELECT_GPIO = "SELECT status FROM gpio WHERE id = {0}"

SELECT_STATUS = "SELECT value FROM status WHERE id = {0}"

# 最新のデータのみ取得
SELECT_LAST_LOG = "SELECT lon, lat FROM log ORDER BY DATE DESC , TIME DESC LIMIT 1"


DEFAULT_INSERT_DATA_METER_1001 = "INSERT OR IGNORE INTO  meter(id, km)values(1001,'0.0');"
DEFAULT_INSERT_DATA_METER_1002 = "INSERT OR IGNORE INTO  meter(id, km)values(1002,'0.0');"
DEFAULT_INSERT_DATA_METER_2001 = "INSERT OR IGNORE INTO  meter(id, km)values(2001,'0.0');"


## 設定
AUTO_COMMIT = 0

dbpath = "./carDB.sqlite3"


def insertLog(values):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()

	
	cursor.executemany(INSERT_LOG, values)

	

    # 保存を実行（忘れると保存されないので注意）
	connection.commit()

	# 接続を閉じる
	connection.close()


def insertGPIO(values):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()

	
	cursor.executemany(INSERT_GPIO, values)

	

    # 保存を実行（忘れると保存されないので注意）
	connection.commit()

	# 接続を閉じる
	connection.close()

def updateMeter(values):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.executemany(UPDATE_METER, values)


    # 保存を実行（忘れると保存されないので注意）
	connection.commit()

	# 接続を閉じる
	connection.close()

def updateState(values):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()

	cursor.executemany(UPDATE_STATE, values)


    # 保存を実行（忘れると保存されないので注意）
	connection.commit()

	# 接続を閉じる
	connection.close()


def selectMeter(id):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.execute(SELECT_METER.format(id ))

	if(cursor.fetchone() == None):
		return None
	else:
		result = cursor.fetchall()

	return result

def selectGPIO(id):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.execute(SELECT_GPIO.format(id ))

	result = cursor.fetchall()

	return result


def selectStatus(id):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.execute(SELECT_STATUS.format(id ))

	result = cursor.fetchall()

	return result[0][0]


def selectLastLog():
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.execute(SELECT_LAST_LOG)

	result = cursor.fetchall()

	return result


def init_DB():
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None
	cursor = connection.cursor()
	
	# CREATE（「id、name」のテーブルを作成）
	cursor.execute(CREATE_LOG)
	cursor.execute(CREATE_METER)
	cursor.execute(CREATE_GPIO)
	cursor.execute(CREATE_TEMP)

	cursor.execute(DEFAULT_INSERT_DATA_METER_1001)
	cursor.execute(DEFAULT_INSERT_DATA_METER_1002)
	cursor.execute(DEFAULT_INSERT_DATA_METER_2001)

    # 保存を実行（忘れると保存されないので注意）
	connection.commit()

	# 接続を閉じる
	connection.close()
