#ifndef TIMING_H
#define TIMING_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void timing_routine(){
    double minTime = 1e+29;
    nextEventType = 0;

    if(nextArrivalTime < minTime){
        minTime = nextArrivalTime;
        nextEventType = ARRIVAL;
    }

    // if(nextDepartTime < minTime){
    //     minTime = nextDepartTime;
    //     nextEventType = DEPARTURE;
    // }

    for (int i = 0; i < servers; i++){
        if(nextDepartTimes[i] < minTime){
            minTime = nextDepartTimes[i];
            nextEventType = DEPARTURE;
            serverDepartureIndex = i;
        }
    }


    if(nextEventType == 0){
        cout << "Error. Event List Empty" << endl;
        exit(1);
    }

    simulTime = minTime;

}

#endif
