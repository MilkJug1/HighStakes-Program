#include "main.h"
#include "pros/misc.h"

void setDrive(int left, int right) {
    LeftMotor = left;
    right_motor = right;
}

void setDriveMotor() {
    int leftJoystick = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (abs(leftJoystick) < 10)
        leftJoystick = 0;
    if (abs(rightJoystick) < 10)
        rightJoystick = 0;
    setDrive(leftJoystick, rightJoystick);

}
