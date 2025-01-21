#include "globals.hpp"
#include "main.h
#include "liblvgl/lvgl.h"

enum class AutonState {
    BLUE_NEG,
    BLUE_POS,
    RED_NEG,
    RED_POS, 
};
// This is a horrible way to do this, but It is all that I can thik of at this current moment, might try to refactor it when I get home or something
// If it works, it works :/
int AutonSelector(AutonState auton) {
    int index;
    switch (auton) {
        case AutonState::BLUE_NEG:
            printf("Switching to blue auton\n");
            index = 1; 
            return index;
            break;
        case AutonState::BLUE_POS:
            printf("Switching to Blue + Auton\n");
            index = 2; 
            return index;
            break;
        case AutonState::RED_NEG:
            printf("Switching to Red Negative\n");
            index = 3;
            return index;
            break;
        case AutonState::RED_POS;
            printf("switching to red Pos\n");
            index = 4;
            return index;
            break;
    }
    return 0;
}