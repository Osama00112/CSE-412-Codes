#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void initialization_routine(){
    simulTime = 0;
    serverStatus = IDLE;
    timeLastEvent = 0;

    delaySum = 0;
    customerDelayedCount = 0;
    currentQueueLength = 0;
    areaUnderQ = 0;
    areaUnderB = 0;
    timeLastEvent = 0;

    nextArrivalTime = generateRandom(A);
    nextDepartTime = INF;
}

#endif
