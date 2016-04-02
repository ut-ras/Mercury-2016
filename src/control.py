#!/usr/bin/python
from bottle import route, request, run, get
import threading
import subprocess
import serial
import time
# import io
import sys
# import picamera

# camera = picamera.PiCamera()
#ser = serial.Serial('/dev/ttyACM0',9600)

#prabhat added
#prabhat added


ard = serial.Serial('/dev/ttyACM1',9600)


CODE_FILE = './code.html'
@route('/control')
def control():
    f = open(CODE_FILE, 'r')
    code = ""
    for line in f:
        code += line
    return code

@route('/control', method='POST')
def do_control():
    keyup = request.forms.get('keyUp')
    leftspeed = request.forms.get('left')
    rightspeed = request.forms.get('right')
    #prabhat added

    if leftspeed is not None:
        ard.write('l');
        ard.write(leftspeed)
        print "left speed is: " + leftspeed
        # TODO: Adjust left speed

    if rightspeed is not None:
        ard.write('r');
        ard.write(rightspeed)
        print "right speed is: " + rightspeed
        # TODO: Adjust right speed
    if keyup is not None:
        print "keyup: " + chr(int(keyup))
        keyup = chr(int(keyup))
        if keyup == 'W':
            ard.write('f');
        elif keyup == 'A':
            # TODO: MOVE LEFT
            pass
        elif keyup == 'S':
            # TODO: MOVE BACKWARD
            ard.write('r')
            pass
        elif keyup == 'D':
            # TODO: MOVE RIGHT
            pass

    #ser.write('r(0-9),')
    #ser.write('l(0-9)')

def startWebsiteThread():
    thread = threading.Thread(target=run, kwargs=dict(host='localhost', port=8000))
    thread.daemon = True
    thread.start()

def pingGoogle():
    while True:
        process = subprocess.Popen("ping -c 2 -q www.google.com > /dev/null && echo $?", stdout=subprocess.PIPE, \
                                    stderr=subprocess.STDOUT, shell=True)
        (out, err) = process.communicate()
        if out != "0\n":
            print "WHOA THERE IS NO INTERNET BRO"
        time.sleep(2)

def LOSThread():
    thread = threading.Thread(target=pingGoogle, args=())
    thread.daemon = True
    thread.start()

def main():
    #startWebsiteThread()
    LOSThread()
    run(host='localhost', port=8000)

if __name__=="__main__":
    main()
