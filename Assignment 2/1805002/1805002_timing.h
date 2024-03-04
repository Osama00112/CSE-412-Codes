#ifndef TIMING_H
#define TIMING_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void timing_routine(){
    double minTime = 1e+29;
    nextEventType = 0;

    for(int i=1; i<=4; i++){
        if(nextEvenTime[i] < minTime){
            minTime = nextEvenTime[i];
            nextEventType = i;
        }
    }

    if(nextEventType == 0){
        cout << "Error. Event List Empty" << endl;
        exit(1);
    }

    simulTime = minTime;

}

#endif
