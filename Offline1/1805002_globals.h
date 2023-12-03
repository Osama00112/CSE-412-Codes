#ifndef GLOBALS_H
#define GLOBALS_H

#include <bits/stdc++.h>
#include "RV_generator.h"

using namespace std;

#define BUSY 1
#define IDLE 0
#define QueueLim 100
#define INF 1e+30

#define ARRIVAL 1
#define DEPARTURE 2

// -----Global variables-----

extern ifstream inputFile;
extern ofstream eventOrderFile, resultFile;

extern double A, S, N;
extern double simulTime;
extern double timeLastEvent;
extern double delaySum;
extern double areaUnderQ;
extern double areaUnderB;
extern double nextArrivalTime;
extern double nextDepartTime;

extern int serverStatus;
extern int customerDelayedCount;
extern int currentQueueLength;
extern int nextEventType;

extern vector<double> arrivalTimes;

// -----Global functions-----

extern double generateRandom(double mean){
    return -mean * log(lcgrand(1));
}

// -----Message Functions-----

extern void customerDelayedMSG(int count){
    eventOrderFile << "\n---------No. of customers delayed: << count <<--------\n" << endl;
}

extern void eventMSG(int totalEvents, int count, int type){
    if(type == ARRIVAL){
        eventOrderFile << 
                totalEvents << ". Next Event: Customer " << count << "Arrival" << endl;
    }else if(type == DEPARTURE){
        eventOrderFile << 
                totalEvents << ". Next Event: Customer " << count << "Departure" << endl;
    }
}

#endif  