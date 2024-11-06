#ifndef GUARD_CONSTANTS_VIAL_H
#define GUARD_CONSTANTS_VIAL_H

// Modes
#define VIAL_GET 0
#define VIAL_CHECK VIAL_GET

#define VIAL_UP 1
#define VIAL_INCREASE VIAL_UP
#define VIAL_ADD VIAL_UP
#define VIAL_GROW VIAL_UP

#define VIAL_DOWN 2
#define VIAL_DECREASE VIAL_DOWN
#define VIAL_REMOVE VIAL_DOWN
#define VIAL_SUBTRACT VIAL_DOWN
#define VIAL_SHRINK VIAL_DOWN
#define VIAL_REDUCE VIAL_DOWN

#define VIAL_REFILL 3
#define VIAL_REFRESH VIAL_REFILL
#define VIAL_RESTORE VIAL_REFILL

// Aspects
#define VIAL_DOSE 0
#define VIAL_SIZE 1

// Measurements
#define EMPTY_VIAL 0
#define VIAL_STANDARD_DOSE 1
#define VIAL_MIN_SIZE 1
#define VIAL_MAX_SIZE 15

// Icon Handling
#define VIAL_NUM_STATES 11

#endif // GUARD_CONSTANTS_VIAL_H
