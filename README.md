# RaspberryPi Car Module
## 概要
Raspberry Pi に以下GPSロガーや、各種アクセサリのコントロールを行います。
## 使用電子部品
|パーツ名|型番|
|---|---|
|Raspberry Pi4 Model B||
|GPSモジュール|GYSFFMANC|
|OSOYOO 5インチディスプレイ(DSI接続)|8905-AVS |
|OSOYOO 5インチディスプレイ(DSI接続)|8905-AVS |

## 構築手順
コンソールを立ち上げる
```shell
sudo su -
apt-get update -y
apt-get upgrade -y
reboot
sudo su -
!pip install geopy
```
以下は設定していない場合のみ実行
```shell
git config --global user.name "ユーザ名"
git config --global user.email "xxxxxxx@yyyy.zzz"
```
以下は本システムのダウンロード
```shell
cd 
git clone https://github.com/xokikurumi/raspberryPi_CarModule.git
cd /etc/systemd/system
vi raspberryPi_CarModule.service
```
以下記載内容
```service
[Unit]
Description=raspberryPi_CarModule
After=syslog.target

[Service]
Type=simple
WorkingDirectory=/usr/share/webiopi/htdocs
ExecStart=/usr/bin/python3 -m webiopi -l /var/log/webiopi -c /etc/webiopi/config
TimeoutStopSec=5
StandardOutput=null

[Install]
WantedBy = multi-user.target
```