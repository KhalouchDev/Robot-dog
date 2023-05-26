int hipAngle1;
int hipAngle2;
int hipHyp;

void IK(legVars leg, float x, float y, float z){
    // ===== Translation =====
    // calculate the hip joint and new leg length based on how far the robot moves sideways
    // first triangle
    hipAngle1 = atan((y/z)) * (180/pi);
    hipHyp = z/cos(hipAngle1);
    // second triangle
    hipAngle2 = asin((c/hipHyp)) * (180/pi);
    leg.hip = hipAngle1 + hipAngle2;
    // calculate new leg length
    leg.h = c/hipAngle2;

    // Calculate the shoulder offset based on how far the leg moves forwards/backwards
    leg.shoulderTheta = atan((x/leg.h)) * (180/pi);
    // Calculate new leg length
    leg.h = z/cos(leg.shoulderTheta);

    // Calculate shoulder and knee angles based on the new leg length
    if (leg.side == 0) {    // Left
        leg.shoulder = ((acos((sq(a) + sq(leg.h) - sq(b))/(2*a*leg.h)))*(180/pi)) + leg.shoulderTheta;
        leg.knee = (acos((sq(a) + sq(b) - sq(leg.h))/(2*a*b))) * (180/pi);
    }
    else {  // Right
        leg.shoulder = ((acos((sq(a) + sq(leg.h) - sq(b))/(-2*a*leg.h)))*(180/pi)) + leg.shoulderTheta;
        leg.knee = (acos((sq(a) + sq(b) - sq(leg.h))/(-2*a*b))) * (180/pi);
    }
}