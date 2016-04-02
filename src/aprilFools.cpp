/*
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


 /*Motor variables*/
 char left_motor_speed;
 char right_motor_speed;
  /*Tracks first byte and byte before that*/
 char last_read_byte = 0;
 char current_byte = 0;

enum MOTOR_DIRECTION{forward, backward};
int motor_direction ;
void updateMotors();

void setup() {/**/
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
}

void loop() {

    if(Serial.available() > 0){
     last_read_byte = current_byte;
     current_byte = Serial.read();
    /* gets a byte off of the serial buffer*/
     Serial.print(current_byte);
     if(current_byte == 'f'){
      motor_direction = forward;
      Serial.println('w');
      updateMotors();
    }
    else if(current_byte == 'r'){
      motor_direction = backward;
      Serial.println('s');
      updateMotors();
    }


 }
  /* myMotor->run(RELEASE);*/
  delay(500);
}
void updateMotors(){
if(motor_direction == FORWARD){
  myMotor->run(FORWARD);
}else{
  myMotor->run(BACKWARD);
}
  myMotor->setSpeed(200);
  delay(50);

}
