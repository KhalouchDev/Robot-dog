#include <Arduino.h>
#include <Servo.h>

Servo shoulder;
Servo knee;

const int l_upper = 13;    // cm
const int l_lower = 13.5; // cm
int height;              // cm

struct angles {
  int shoulder;
  int knee;
} leg1, leg2, leg3, leg4;

void inverse_kinematics(int h, int lu, int ll, int leg){
  int k_rad;
  int k_angle;
  int s_rad;
  int s_angle;

  s_rad = ((pow(h, 2) + pow(lu, 2) - pow(ll, 2))/(2*lu*h));
  s_rad = acos(s_rad);
  s_angle = s_rad*(180/PI);

  k_rad = ((pow(lu, 2) + pow(ll, 2) - pow(h, 2))/(2*lu*ll));
  k_rad = acos(k_rad);
  k_angle = k_angle*(180/PI);

  switch(leg){
    case 1:
      leg1.shoulder = s_angle;
      leg1.knee = k_angle;
    case 2:
      leg2.shoulder = s_angle;
      leg2.knee = k_angle;
    case 3:
      leg3.shoulder = s_angle;
      leg3.knee = k_angle;
    case 4:
      leg3.shoulder = s_angle;
      leg4.knee = k_angle;
  }
}

void setup() {
  Serial.begin(9600);

  shoulder.attach(10);
  knee.attach(9);
  
  Serial.println("Starting loop.");
}

void loop() {
  inverse_kinematics(height, l_upper, l_lower, 1);

  shoulder.write(leg1.shoulder);
  knee.write(leg1.shoulder);

  Serial.println("Angles:");
  Serial.println(leg1.shoulder);
  Serial.println(leg1.knee);
}