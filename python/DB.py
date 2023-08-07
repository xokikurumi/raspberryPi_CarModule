#!usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

# テーブル作成クエリ
CREATE_LOG = "CREATE TABLE IF NOT EXISTS log('date' TEXT, 'time' TEXT, lon TEXT, lat TEXT)"
CREATE_METER = "CREATE TABLE IF NOT EXISTS meter(id INT, km TEXT)"

# データ挿入
INSERT_LOG = "INSERT INTO log('date', 'time', lon, lat)VALUES(?, ?, ?, ?)"
# データ更新
UPDATE_METER = "UPDATE meter SET km = ? WHERE id = ?"

# データ取得
SELECT_METER = "SELECT km FROM meter WHERE id = {0}"

## 設定
AUTO_COMMIT = 0

dbpath = "./carDB.sqlite3"



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
	
    # 保存を実行（忘れると保存されないので注意）
#	connection.commit()

	# 接続を閉じる
	connection.close()


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


def selectMeter(id):
	# データベース接続とカーソル生成
	# dppathと同名のファイルがなければ、DBファイルが作成されます。
	connection = sqlite3.connect(dbpath)

	# 自動コミットにする場合は下記を指定（コメントアウトを解除のこと）
	if AUTO_COMMIT == 1:
		connection.isolation_level = None

	cursor = connection.cursor()


	cursor.execute(SELECT_METER.format(id ))

	result = cursor.fetchall()

	return result