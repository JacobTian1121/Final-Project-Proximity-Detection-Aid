//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "siren.h"

#include "distance.h"

#include "alarm.h"



//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut sirenPin(PC_9_ALT0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool sirenState = OFF;
static int currentStrobeTime = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sirenInit()
{
    sirenPin.period(1.0f);
    sirenPin.write(1.0f);
}

bool sirenStateRead()
{
    return sirenState;
}

void sirenStateWrite( bool state )
{
    sirenState = state;
}


void sirenUpdate( float StrobeTime )
{
    if( sirenState ) {
            sirenPin.period(StrobeTimeRead());
            sirenPin.write(0.5f);
            currentStrobeTime = StrobeTimeRead();
    } else {
        sirenPin.write(1.0f);
        currentStrobeTime = 0;
    }
}

//=====[Implementations of private functions]==================================