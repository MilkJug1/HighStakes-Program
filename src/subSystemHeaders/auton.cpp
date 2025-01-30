#include "main.h"

//TODO: Start working on ideas for the other Auton states
// Autons Needing worked on
// - Blue Neg
// - Red Pos
// - Red Neg
//
//TODO: Port the Python code for the auton, then work on the others.
//NOTE: Got bot working driving, now time for auton, so happy right now
//


void RedPos(){
    chassis.moveToPose(10, 10, 90, 1000);

}

void RedNeg() {

    chassis.moveToPose(20, 20, 90, 1000);

}

void BlueNeg() {

    chassis.moveToPose(5, 5, 45, 1000);

}

void BluePos() {

    chassis.moveToPose(15, 15, 30, 1000);

}
