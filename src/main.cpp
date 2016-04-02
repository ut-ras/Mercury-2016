/*UT IEEE RAS Mercury 2016*/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);

/*Motor Variables*/
int left_motor_speed;
int right_motor_speed;
/*Tracks first byte and byte before that*/
char last_read_byte = 0;
char current_byte = 0;
/*Motor Variables*/

enum MOTOR_DIRECTION {forward, backward};
int motor_direction;
void updateMotors();

void setup() { 
        Serial.begin(9600); 
        Serial.println("Adafruit Motorshield v2 - DC Motor test!");
        AFMS.begin(); 
        myMotor->setSpeed(150);
        myMotor->run(FORWARD);
        myMotor->run(RELEASE);
}

void loop() {

        if(Serial.available() > 0) {
                last_read_byte = current_byte;
                current_byte = Serial.read();
                /* gets a byte off of the serial buffer*/
                Serial.println(current_byte);
                if(current_byte == 'f') {
                        motor_direction = forward;
                }
                else if(current_byte == 'r') {
                        motor_direction = backward;
                }
                else if( (0x30 <= current_byte) && (current_byte <=0x39))
                {
                        current_byte = (current_byte - 0x30);
                        if(last_read_byte == 'l')
                        {
                                left_motor_speed = map (current_byte,0,9,0,255);
                                Serial.println(left_motor_speed);
                              }
                        else if (last_read_byte == 'r')
                        {
                                right_motor_speed = map (current_byte,0,9,0,255);
                                Serial.println(right_motor_speed);
                        }
                }
                updateMotors();

        }
        /* myMotor->run(RELEASE);*/
        delay(500);
}
void updateMotors(){
        if(motor_direction == FORWARD)
        {
                myMotor->run(FORWARD);
        }else
        {
                myMotor->run(BACKWARD);
        }
        myMotor->setSpeed(left_motor_speed);
        delay(50);
}
