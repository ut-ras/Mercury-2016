#!/usr/bin/python
from bottle import route, request, run, get
import threading
import subprocess
# import serial
import time
# import io
import sys
# import picamera

# camera = picamera.PiCamera()
# ser = serial.Serial('/dev/ttyUSB0',9600)

CODE_FILE = './code.html'

@route('/control')
def control():
    f = open(CODE_FILE, 'r')
    code = ""
    for line in f:
        code += line
    return code 
    
@route('/action', method='POST')
def action():
    val = request.forms.get('strState')
    val2 = request.forms.get('strState2')
    keyCode = request.forms.get('keyPressed')

    #ser.write('r(0-9),')
    #ser.write('l(0-9)')

def startWebsiteThread():
    thread = threading.Thread(target=run, kwargs=dict(host='localhost', port=8000))
    thread.daemon = True
    thread.start()

def pingGoogle():
    process = subprocess.Popen("ping -c 2 -q www.google.com > /dev/null && echo $?", stdout=subprocess.PIPE, \
                               stderr=subprocess.STDOUT, shell=True)
    (out, err) = process.communicate()
    if out != "0\n":
        print "WHOA THERE IS NO INTERNET BRO"
        
def LOSThread():
    thread = threading.Thread(target=pingGoogle, args=())
    thread.daemon = True
    thread.start()

def main():
    startWebsiteThread()
    while True:
        LOSThread()
        # Explicit thread yield
        time.sleep(2)

if __name__=="__main__":
    main()
