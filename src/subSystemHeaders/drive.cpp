#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <cmath>
#include <cstdlib>

void setDrive(int left, int right) {
    // LeftMotor = left;
    // right_motor = right;
    printf("%i, %i", left, right);
}

void resetDriveEncoders() {
    LeftMotor.tare_position();
    right_motor.tare_position();
    Hook.tare_position();
    ConGP.tare_position();
}

double avgDriveEncVal() {
    return (fabs(LeftMotor.get_position()) + fabs(right_motor.get_position())) / 2;
}

void setDriveMotor() {
    // int leftJoystick = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    // int rightJoystick = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    //
    // if (abs(leftJoystick) < 10)
    //     leftJoystick = 0;
    // if (abs(rightJoystick) < 10)
    //     rightJoystick = 0;
    // setDrive(leftJoystick, rightJoystick);

}

// Autonomous Functions
// Might be able to use Okapi for this ngl

void translate(int units, int voltage) {
    int direction = abs(units) / units; // either 1 or -1
    resetDriveEncoders();

    while(avgDriveEncVal() < abs(units)) {
        setDrive(voltage * direction, voltage);
        pros::delay(10);
    }

    setDrive(-10 * direction, -10 *direction);

    pros::delay(50);

    setDrive(0,0);
}
