/*
Front left leg:
  Hip: 11
  Shoulder: 10
  Knee: 9
Front right leg:
  Hip: 6
  Shoulder: 5
  Knee: 3
Back left leg:
  Hip: A0
  Shoulder: A1
  Knee: A2
Back right leg:
  Hip: A3
  Shoulder: A4
  Knee: A5
*/

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Servo.h>
#include <IK.cpp>

const float a = 13; // Upper link length (cm)
const float b = 13; // Lower link length (cm)
const float c = 0; // Distance between hip and shoulder (cm)

const float pi = M_PI;

// Define three angles, {x,y,z} coordinates and three servos for each leg
struct legVars{
  // Left (0) or right (1) leg
  int side;
  // Servo motors
  Servo Ship;
  Servo Sshoulder;
  Servo Sknee;
  // Angle variables
  int hip;
  int shoulder;
  int knee;
  int shoulderTheta;
  // Distance variables
  float x;
  float y;
  float z;
  float h;
} FRleg, FLleg, BRleg, BLleg;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void changeHeight(int h){
    FLleg.h = BLleg.h = FRleg.h = BRleg.h = h;

    // Calculate left side
    FLleg.shoulder = BLleg.shoulder = (acos((sq(a) + sq(FLleg.h) - sq(b))/(2*a*FLleg.h))) * (180/pi);
    FLleg.knee = BLleg.knee = (acos((sq(a) + sq(b) - sq(FLleg.h))/(2*a*b))) * (180/pi);
    // Calculate right side

    FRleg.shoulder = BRleg.shoulder = (acos((sq(a) + sq(FLleg.h) - sq(b))/(-2*a*FLleg.h))) * (180/pi);
    FRleg.knee = BRleg.knee = (acos((sq(a) + sq(b) - sq(FLleg.h))/(-2*a*b))) * (180/pi);

    FLleg.Sshoulder.write(FLleg.shoulder);
    FLleg.Sknee.write(FLleg.knee);
    BLleg.Sshoulder.write(BLleg.shoulder);
    BLleg.Sknee.write(BLleg.knee);
    
    FRleg.Sshoulder.write(FRleg.shoulder);
    FRleg.Sknee.write(FRleg.knee);
    BRleg.Sshoulder.write(BRleg.shoulder);
    BRleg.Sknee.write(BRleg.knee);
}

void setup(){
  // lcd
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Robot Dog");

  // configure sides
  FLleg.side = BLleg.side = 0;
  FRleg.side = BRleg.side = 1;

  // Front left leg
  FLleg.Ship.attach(11);
  FLleg.Sshoulder.attach(10);
  FLleg.Sknee.attach(9);
  // Front right leg
  FRleg.Ship.attach(6);
  FRleg.Sshoulder.attach(5);
  FRleg.Sknee.attach(3);
  // Back left leg
  BLleg.Ship.attach(A0);
  BLleg.Sshoulder.attach(A1);
  BLleg.Sknee.attach(A2);
  // Back right leg
  BRleg.Ship.attach(A3);
  BRleg.Sshoulder.attach(A4);
  BRleg.Sknee.attach(A5);

  Serial.begin(9600);
}

void loop(){

}