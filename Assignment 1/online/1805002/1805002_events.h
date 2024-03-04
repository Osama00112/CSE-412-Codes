#ifndef EVENT_H
#define EVENT_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void arrival(){
    double delay;
    nextArrivalTime = simulTime + generateRandom(A);
    customerArrivalCount++;
    eventMSG(totalEvents, customerArrivalCount, ARRIVAL, 0);

    // if(serverStatus == IDLE){
    //     delay = 0;
    //     customerDelayedCount++;
    //     customerDelayedMSG(customerDelayedCount);
    //     serverStatus = BUSY;
    //     nextDepartTime = simulTime + generateRandom(S);

    // }else{
    //     currentQueueLength++;
    //     if(currentQueueLength > QueueLim){
    //         cout << "Queue Limit Exceeded" << endl;
    //         exit(2); 
    //     }

    //     arrivalTimes.push_back(simulTime);
    // }

    int condition = 0;
    for (int i=0; i<servers; i++){
        if(serverStatuses[i] == IDLE){
            delay = 0;
            serverStatuses[i] = BUSY;
            nextDepartTimes[i] = simulTime + generateRandom(S);
            condition = 1;
            break;
        }
    }

    if(condition == 0){  // meaning no servers are idle
        currentQueueLength++;
        if(currentQueueLength > QueueLim){
            cout << "Queue Limit Exceeded" << endl;
            exit(2); 
        }

        arrivalTimes.push_back(simulTime);
    }else{
        customerDelayedCount++;
        customerDelayedMSG(customerDelayedCount);
    }


}

void departure(){
    double delay;
    customerDepartureCount++;
    eventMSG(totalEvents, customerDepartureCount, DEPARTURE, serverDepartureIndex);

    //sever departure index is known



    // if(currentQueueLength == 0){
    //     serverStatus = IDLE;
    //     nextDepartTime = INF;
    // }else{
    //     currentQueueLength--;
    //     delay = simulTime - arrivalTimes[0];
    //     delaySum += delay;
    //     customerDelayedCount++;
    //     customerDelayedMSG(customerDelayedCount);
    //     nextDepartTime = simulTime + generateRandom(S);
    //     arrivalTimes.erase(arrivalTimes.begin());
    // }

    if(currentQueueLength == 0){
        serverStatuses[serverDepartureIndex] = IDLE;
        nextDepartTimes[serverDepartureIndex] = INF;
    }
    else{
        currentQueueLength--;
        delay = simulTime - arrivalTimes[0];
        delaySum += delay;
        customerDelayedCount++;
        customerDelayedMSG(customerDelayedCount);
        nextDepartTimes[serverDepartureIndex] = simulTime + generateRandom(S);
        arrivalTimes.erase(arrivalTimes.begin());
    }

}

#endif  
