#include "api.h"
#include "main.h"

extern int controlScheme;

// enum class AutonState {
//     RED_POS,
//     RED_NEG,
//     BLUE_POS,
//     BLUE_NEG,
// };// Motors
extern pros::Motor LeftMotor;
extern pros::Motor right_motor;

//Hook
extern pros::Motor Hook;

// Conveyor
extern pros::Motor Con1;
extern pros::Motor Con2;

extern pros::MotorGroup ConGP;

extern pros::Controller Controller;


// GUI STUFF

// void btnSetToggled(lv_obj_t * btn, bool toggled);

extern int AutonSel;
