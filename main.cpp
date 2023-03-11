//=====[Libraries]=============================================================
#include "glasses_detector.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    GlassesDetectorInit();
    while (true) {
        GlassesDetectorUpdate();
    }
}