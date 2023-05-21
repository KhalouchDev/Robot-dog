#include<Arduino.h>
#include<Servo.h>

const float a = 13; // Upper link length (cm)
const float b = 13; // Lower link length (cm)
const float c = 0; // Distance between hip and shoulder (cm)

const float pi = M_PI;

// Define three angles, {x,y,z} coordinates and three servos for each leg
struct legVars{
  // Servo motors
  Servo Ship;
  Servo Sshoulder;
  Servo Sknee;
  // Angle variables
  int hip;
  int shoulder;
  int knee;
  // Distance variables
  float x;
  float y;
  float z;
  float h;
} FRleg, FLleg, BRleg, BLleg;

void changeHeight(){
  for (int h = 10; h<=20; h++){
    FLleg.h = BLleg.h = h;
    FLleg.shoulder = BLleg.shoulder = (acos((sq(a) + sq(FLleg.h) - sq(b))/(2*a*FLleg.h))) * (180/pi);
    FLleg.knee = BLleg.knee = (acos((sq(a) + sq(b) - sq(FLleg.h))/(2*a*b))) * (180/pi);

    FRleg.h = BRleg.h = h;
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

    Serial.print("Left:");
    Serial.print(FLleg.shoulder);
    Serial.print(",");
    Serial.print(FLleg.knee);
    Serial.println();
    Serial.print("Right:");
    Serial.print(FRleg.shoulder);
    Serial.print(",");
    Serial.print(FRleg.knee);
    Serial.println();

    delay(10);
  }

  for (int h = 20; h>=10; h--){
    FLleg.h = BLleg.h = h;
    FLleg.shoulder = BLleg.shoulder = (acos((sq(a) + sq(FLleg.h) - sq(b))/(2*a*FLleg.h))) * (180/pi);
    FLleg.knee = BLleg.knee = (acos((sq(a) + sq(b) - sq(FLleg.h))/(2*a*b))) * (180/pi);

    FRleg.h = BRleg.h = h;
    FRleg.shoulder = BRleg.shoulder = (acos((sq(a) + sq(FRleg.h) - sq(b))/(-2*a*FRleg.h))) * (180/pi);
    FRleg.knee = BRleg.knee = (acos((sq(a) + sq(b) - sq(FRleg.h))/(-2*a*b))) * (180/pi);

    FLleg.Sshoulder.write(FLleg.shoulder);
    FLleg.Sknee.write(FLleg.knee);
    BLleg.Sshoulder.write(BLleg.shoulder);
    BLleg.Sknee.write(BLleg.knee);
    
    FRleg.Sshoulder.write(FRleg.shoulder);
    FRleg.Sknee.write(FRleg.knee);
    BRleg.Sshoulder.write(BRleg.shoulder);
    BRleg.Sknee.write(BRleg.knee);

    Serial.print("Left:");
    Serial.print(FLleg.shoulder);
    Serial.print(",");
    Serial.print(FLleg.knee);
    Serial.println();
    Serial.print("Right:");
    Serial.print(FRleg.shoulder);
    Serial.print(",");
    Serial.print(FRleg.knee);
    Serial.println();
    
    delay(10);
  }
}

void setup(){
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
  changeHeight();
}