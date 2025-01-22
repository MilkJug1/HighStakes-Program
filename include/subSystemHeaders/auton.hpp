#include "main.h"

// This will be moved into another file, just here for testing purposes.
enum class AutonType {
    BLUE_POS,
    BLUE_NEG,
    RED_POS,
    RED_NEG,
};

extern const AutonType& get_auton_type();


int AutonSelector(AutonState auton);
