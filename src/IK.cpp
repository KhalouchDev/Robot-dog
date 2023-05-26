void IK(legVars leg, float x, float y, float z){
    // ===== Translation =====

    // Calculate the shoulder offset based on how far the leg moves forwards/backwards
    leg.shoulderTheta = atan((x/z));
    // Calculate new leg length
    leg.h = z/cos(leg.shoulderTheta);

    // Calculate shoulder and knee angles based on the new leg length
    if (leg.side == 0) {    // Left
        leg.shoulder = ((acos((sq(a) + sq(leg.h) - sq(b))/(2*a*leg.h))) * (180/pi)) + leg.shoulderTheta;
        leg.knee = (acos((sq(a) + sq(b) - sq(leg.h))/(2*a*b))) * (180/pi);
    }
    else {  // Right
        leg.shoulder = ((acos((sq(a) + sq(leg.h) - sq(b))/(-2*a*leg.h))) * (180/pi)) + leg.shoulderTheta;
        leg.knee = (acos((sq(a) + sq(b) - sq(leg.h))/(-2*a*b))) * (180/pi);
    }
}