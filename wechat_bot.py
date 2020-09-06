# coding:UTF-8 

import itchat
import requests
import random
from snownlp import SnowNLP
import serial
import time

port = 'COM6'
bitspeed = 9600
ser = serial.Serial(port,bitspeed,bytesize=8,parity='N',stopbits = 1,timeout=0.5,rtscts=False)

robot_key = ''	#Add your code on here
happy_pic = ['.\\expression\\happy1.jpg','.\\expression\\happy2.jpg']
sad_pic = ['.\\expression\\sad1.jpg','.\\expression\\sad2.jpg']

command_set = [u'开空调',]


def send_cmd(cmd):
	print 'Send command to arduino...'
	ser.write(cmd)
	print 'Finish send.'

@itchat.msg_register([itchat.content.TEXT,itchat.content.PICTURE])
def reply_handle(msg):
	me = itchat.get_friends()[0]
	print 'From:',msg.user.nickName,msg['Text']
	if msg.type == itchat.content.PICTURE:

		msg.user.send_image('pict.jpg')
		msg.user.send(u'我是人工智障,看不懂图片。。。。')
		#msg.download(msg.fileName)
	if msg['Text'][0] == '#':
		msg.user.send(u'Get a new command!')
		msg.user.send(u'打开空调中...')
		send_cmd('1')
		msg.user.send(u'打开完成...')

	else:

		data = {
			"key":u"",	#Add your key on here
		    "info":msg['Text']
		}
		rep = requests.post(url='http://www.tuling123.com/openapi/api',data=data).json()

		if random.randint(1,100) > 60:
			s = SnowNLP(msg['Text'])
			if s.sentiments > 0.6:
				msg.user.send_image(msg.user.send_image(random.choice(happy_pic)))
			else:
				msg.user.send_image(msg.user.send_image(random.choice(sad_pic)))

			
		
		if rep['code'] == '40001':
			msg.user.send(u"Error...the robot can't reply you")
		else:
			msg.user.send(rep['text'])


itchat.auto_login(hotReload = True)
# frinedList = itchat.get_friends(update = True)[1:]
# for frined in frinedList:
# 	print frined['UserName']
# itchat.send(u'Hello world.By robot',u'lzk66666666666666')
# author = itchat.search_friends(nickName = u'')[0]
# author.send('Hello world.By robot')
itchat.run()
