//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"
#include "siren.h"
#include "distance.h"
#include "ldr_sensor.h"


//=====[Declaration of private defines]========================================

#define STROBE_TIME_INTRUDER_ALARM          1000
#define STROBE_TIME_FIRE_ALARM               500
#define STROBE_TIME_FIRE_AND_INTRUDER_ALARM  100


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool alarmState;

//=====[Declarations (prototypes) of private functions]========================

static void alarmDeactivate();

//=====[Implementations of public functions]===================================

void alarmInit()
{
    alarmState = OFF;
    sirenInit();
    DistanceInit();
        
}

void alarmUpdate()
{
    if(ldrSensorRead() >= 0.1){
        if (DistanceReadAVG() > 300.0){
        sirenStateWrite(OFF);
    } else {
        sirenStateWrite(ON);
        sirenUpdate( StrobeTimeRead() );
    }
} else {
    if(DistanceReadAVG() > 400.0){
         sirenStateWrite(OFF);
    } else{
        sirenStateWrite(ON);
        sirenUpdate( StrobeTimeRead() );
    }
}
}

bool alarmStateRead()
{
    return alarmState;
}

//=====[Implementations of private functions]==================================

static void alarmDeactivate()
{
    sirenStateWrite(OFF);
}
