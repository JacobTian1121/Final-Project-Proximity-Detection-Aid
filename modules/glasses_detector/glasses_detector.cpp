//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "glasses_detector.h"

#include "ldr_sensor.h"

#include "alarm.h"

#include "distance.h"
#include "siren.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void GlassesDetectorInit()
{
    alarmInit();
    DistanceInit();
    sirenInit();
}

void GlassesDetectorUpdate()
{
    alarmUpdate();
    DistanceUpdate();
    //sirenUpdate(float strobeTime);
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
