#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);
//Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);
//Adafruit_DCMotor *Motor3 = AFMS.getMotor(3);
//Adafruit_DCMotor *Motor4 = AFMS.getMotor(4);

String readString;

void setup()
{
  Serial.begin(9600);  // initialize serial communications at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  Motor1->setSpeed(0);
  Motor1->run(FORWARD);
  Motor1->run(BACKWARD);
  Motor1->run(RELEASE);
  
//  Motor2->setSpeed(0);
//  Motor2->run(FORWARD);
//  Motor2->run(BACKWARD);
//  Motor2->run(RELEASE);
}

void loop()
{
  if(Serial.available() > 0)
  {
    // serial read section
    readString = Serial.readString();  //gets one byte from serial buffer
    if (readString.length() > 0)
    {
      if (readString[0] == 'W')
      {
        Serial.print("Arduino received: ");  
        Serial.println(readString[0]); //see what was received
        Motor1->run(FORWARD);
        Motor1->setSpeed(255);
      }
      else if (readString[0] == 'B')
      {
        Serial.print("Arduino received: ");  
        Serial.println(readString[0]); //see what was received
        Motor1->run(FORWARD);
        Motor1->setSpeed(0);
      }
    }

    // serial write section
    Serial.print("\n");
    Serial.flush();
  }
}

