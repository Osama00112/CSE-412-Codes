#ifndef EVENT_H
#define EVENT_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void arrival(){
    double delay;
    nextArrivalTime = simulTime + generateRandom(A);
    customerArrivalCount++;
    eventMSG(totalEvents, customerArrivalCount, ARRIVAL);

    if(serverStatus == IDLE){
        delay = 0;
        customerDelayedCount++;
        customerDelayedMSG(customerDelayedCount);
        serverStatus = BUSY;
        nextDepartTime = simulTime + generateRandom(S);

    }else{
        currentQueueLength++;
        if(currentQueueLength > QueueLim){
            cout << "Queue Limit Exceeded" << endl;
            exit(2); 
        }

        arrivalTimes.push_back(simulTime);
    }
}

void departure(){
    double delay;
    customerDepartureCount++;
    eventMSG(totalEvents, customerDepartureCount, DEPARTURE);

    if(currentQueueLength == 0){
        serverStatus = IDLE;
        nextDepartTime = INF;
    }else{
        currentQueueLength--;
        delay = simulTime - arrivalTimes[0];
        delaySum += delay;
        customerDelayedCount++;
        customerDelayedMSG(customerDelayedCount);
        nextDepartTime = simulTime + generateRandom(S);
        arrivalTimes.erase(arrivalTimes.begin());
    }

}

#endif  
