#ifndef EVENT_H
#define EVENT_H

#include <bits/stdc++.h>
#include "1805002_globals.h"

using namespace std;

void order_arrival_routine(){
    currentInvLevel += currentOrderAmount;

    nextEvenTime[ORDER_ARIVAL] = INF;
}

void demand_routine(){
    int newDemand = getRandomDemandSize();

    currentInvLevel -= newDemand;

    nextEvenTime[DEMAND] = simulTime + generateRandom(beta_D);
}

void inv_check_routine(int policyIndex){
    double s = policies[policyIndex].first;
    double S = policies[policyIndex].second;
    if(currentInvLevel < s){
        currentOrderAmount = S - currentInvLevel;
        orderingCost += (K + incr * currentOrderAmount);

        nextEvenTime[ORDER_ARIVAL] = simulTime + uniformRV(m, M);
    }
    else{
        currentOrderAmount = 0;
    }
    
    nextEvenTime[INV_CHECK] = simulTime + 1;
}


void calculateStats(){
    double timeSinceLastEvent = simulTime - timeLastEvent;
    timeLastEvent = simulTime;

    if (currentInvLevel < 0){
        areaUnderShortage -= currentInvLevel * timeSinceLastEvent;
    }
    else{
        areaUnderHolding += currentInvLevel * timeSinceLastEvent;
    }

}

#endif  
