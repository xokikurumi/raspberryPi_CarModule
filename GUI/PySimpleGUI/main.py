import PySimpleGUI as sg

layout = [
	[sg.Text("オドメータ"), sg.Text("",key = 'odoLabel'),sg.Text("km") ],
	[sg.Text("トリップメータ"), sg.Text("",key = 'tripLabel'),sg.Text("km") ],
	[sg.Text("気温"), sg.Text("",key = 'tempLabel'),sg.Text("℃") ],
	[sg.Text("湿度"), sg.Text("",key = 'humLabel'),sg.Text("%") ],
	[sg.Button("ハザード"),sg.Button(""),sg.Button("リセット"),sg.Button("トリップB"),sg.Button("トリップA")],
	[sg.Button("USB", key="USB_L"),sg.Button("FAN", key="FAN_L"),sg.Button(""),sg.Button("FAN", key="FAN_R"),sg.Button("USB", key="USB_R")],
]

window = sg.Window("モジュール",layout)

while True:

	pass

window.close()