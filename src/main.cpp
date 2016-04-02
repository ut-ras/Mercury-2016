 // /*UT Robotics and Automation Society Mercury 2016 */
 // #include <Arduino.h>
 // #include <Wire.h>
 // #include <Adafruit_MotorShield.h>
 // #include "utility/Adafruit_MS_PWMServoDriver.h"
 //
 // Adafruit_MotorShield AFMS = Adafruit_MotorShield();
 // Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
 // Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
 //
 // /*Tracks first byte and byte before that*/
 // char last_read_byte = 0;
 // char current_byte = 0;
 //
 // /*Motor variables*/
 // char left_motor_speed;
 // char right_motor_speed;
 // enum MOTOR_DIRECTION{forward, backward};
 // int motor_direction ;
 //
 //
 // void updateMotors();
 // void leftTurn();
 // void rightTurn();
 //
 // void setup()
 // {
 //   AFMS.begin();
 //   motor_direction = forward;
 //   leftMotor->run(RELEASE);
 //   rightMotor->run(RELEASE);
 //   Serial.begin(9600);   initialize serial communications at 9600 bps
 //    Set the speed to start, from 0 (off) to 255 (max speed)
 //   leftMotor->setSpeed(150);
 //   leftMotor->run(FORWARD);
 //    turn on motor
 //   leftMotor->run(RELEASE);
 //
 //
 // }
 //
 // void loop()
 // {
 //
 //   if(Serial.available() > 0){
 //     last_read_byte = current_byte;
 //     current_byte = Serial.read();  gets a byte off of the serial buffer
 //     /* Serial.print(current_byte);*/
 //
 //     if(current_byte == 'f'){
 //       motor_direction = forward;
 //       Serial.println('w');
 //     }
 //     else if(current_byte == 'r')
 //     {
 //       motor_direction = backward;
 //       Serial.println('s');
 //     }
 //     else if( (0 <= current_byte) && (current_byte <=9))
 //     {
 //       if(last_read_byte == 'l')
 //       {
 //         left_motor_speed = map (current_byte,0,9,0,255);
 //       }
 //       else if (last_read_byte == 'r')
 //       {
 //         right_motor_speed = map (current_byte,0,9,0,255);
 //       }
 //     }
 //     else if(current_byte == 'b')
 //     {
 //       left_motor_speed = 0;
 //       right_motor_speed = 0;
 //     }
 //     else if(current_byte == 'd')
 //     {
 //       /*Recorded 90 degree right turn code*/
 //     }
 //     else if(current_byte == 'a')
 //     {
 //       /*Recorded 90 degree left turn code*/
 //     }
 //   }
 //
 // updateMotors();
 // }
 // void updateMotors()
 // {
 //   /*Set movement direction*/
 //   if(motor_direction == forward)
 //   {
 //     leftMotor -> run(FORWARD);
 //     rightMotor -> run(FORWARD);
 //   }
 //   else
 //   {
 //     leftMotor -> run(BACKWARD);
 //     rightMotor -> run(BACKWARD);
 //   }
 //
 //   /*Update left and right motor speed */
 //   leftMotor  -> setSpeed(left_motor_speed);
 //   rightMotor -> setSpeed(right_motor_speed);
 //
 // }
 // void leftTurn()
 // {
 //   /*TODO add code for a recorded leftTurn*/
 // }
 // void rightTurn()
 // {
 //     /*TODO add code for a recorded rightTurn*/
 // }
