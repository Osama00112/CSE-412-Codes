#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <bits/stdc++.h>
#include "1805002_globals.h"


void initialization_routine(){
    simulTime = 0;
    timeLastEvent = 0;
    currentOrderAmount = 0;

    orderingCost = 0;
    expressOrderingCost = 0;
    //holdingCost = 0;
    //backlogCost = 0;
    areaUnderShortage = 0;
    areaUnderHolding = 0;

    nextEvenTime[ORDER_ARIVAL] = INF;
    nextEvenTime[DEMAND] = simulTime + generateRandom(beta_D);
    nextEvenTime[END_OF_SIM] = N;
    nextEvenTime[INV_CHECK] = 0;
    nextEvenTime[EXPRESS_ORDER] = INF;

    currentInvLevel = I;
}

void trialInitialize(){
    //clear the vectors
    avgTotalCost.clear();
    avgTotalCostWithExpressOrder.clear();
    avgOrderingCostPerPolicy.clear();
    avgHoldingCostPerPolicy.clear();
    avgShortageCostPerPolicy.clear();
}

#endif
