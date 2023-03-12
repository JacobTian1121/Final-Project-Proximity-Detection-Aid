//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"
#include "siren.h"
#include "ldr_sensor.h"
#include "distance.h"

//=====[Declaration of private defines]========================================
#define  distanceMaxSample   10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
Ticker stopWatch;
InterruptIn Echo(PF_13);
DigitalOut trig(PF_14);
//=====[Declaration of external public global variables]=======================
float Echodistance;
float EchodistanceArray[distanceMaxSample];
float StrobeTime;
//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
static int echoTimer = 0;
static int EchoPulseTime = 0;


//=====[Declarations (prototypes) of private functions]========================
static void EchoFallCallback();
static void EchoRiseCallback();

void timerCounter();

//=====[Implementations of public functions]===================================



void DistanceInit()
{
    Echo.rise(&EchoRiseCallback);
    Echo.fall(&EchoFallCallback);
    stopWatch.attach (&timerCounter, 10us);
}

void DistanceUpdate()
{
    trig = ON;
    wait_us(10);
    trig = OFF;
}

float DistanceRead()
{
    Echodistance = EchoPulseTime / 58.0;// translate it in to cm 
    return Echodistance;
}

float StrobeTimeRead()
{
    if (ldrSensorRead() >= 0.1){
        StrobeTime = 0.0034 * DistanceReadAVG() - 0.033;
        if((0.001 < StrobeTime) && (StrobeTime < 1)){
            return StrobeTime;
        }else{
            return 0.5;
        }
    } else 
        StrobeTime = 0.0026 * DistanceReadAVG() - 0.025;
        if ((0.001 < StrobeTime) && (StrobeTime < 1)){
            return StrobeTime;
        } else{
            return 0.5;
    }
}

float DistanceReadAVG()
{
    static int distanceSampleIndex = 0;
    float distanceReadSum = 0.0;
    float distanceAverage = 0.0;
    int i = 0;

    EchodistanceArray[distanceSampleIndex] = DistanceRead();
    distanceSampleIndex++;
    if (distanceSampleIndex > distanceMaxSample){
        distanceSampleIndex = 0;
    }
    distanceReadSum = 0.0;
    for ( i = 0 ; i < distanceMaxSample ; i++ ){
        distanceReadSum = distanceReadSum + EchodistanceArray[i];
    }
    distanceAverage = distanceReadSum / distanceMaxSample;
    return distanceAverage;
}


void timerCounter()
{
    echoTimer++;
}

static void EchoRiseCallback()
{
 echoTimer = 0;
}

static void EchoFallCallback()
{
 EchoPulseTime = echoTimer * 10; // change the unit of time, since the echoTimer is 10us.
}

