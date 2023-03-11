//=====[#include guards - begin]===============================================

#ifndef _DISTANCE_H_
#define _DISTANCE_H_

//=====[Declaration of public defines]=========================================

#define SYSTEM_TIME_INCREMENT_MS   60

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void DistanceInit();
void DistanceUpdate();
float DistanceRead();
float DistanceReadAVG();
float StrobeTimeRead();

//=====[#include guards - end]=================================================

#endif // _DISTANCE_H_
