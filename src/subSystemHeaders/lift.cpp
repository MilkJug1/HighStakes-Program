#include "main.h"
#include "subSystemHeaders/lift.hpp"


void setConveyor(int button) {
    // ConGP = button;
}

void setConveyorMotors() {
    int rButtons = 127 * (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));

    setConveyor(rButtons);
}
