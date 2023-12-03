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

ifstream inputFile;
ofstream eventOrderFile, resultFile;

double A, S, N;
double simulTime;
double timeLastEvent;
double delaySum;
double areaUnderQ;
double areaUnderB;
double nextArrivalTime;
double nextDepartTime;

int serverStatus;
int customerDelayedCount;
int currentQueueLength;
int nextEventType;

int totalEvents;
int customerArrivalCount;
int customerDepartureCount;

vector<double> arrivalTimes;

// -----Global functions-----

double generateRandom(double mean){
    return -mean * log(lcgrand(1));
}

// -----Message Functions-----

void customerDelayedMSG(int count){
    eventOrderFile << "\n---------No. of customers delayed: " << count << "--------\n" << endl;
}

void eventMSG(int totalEvents, int count, int type){
    if(type == ARRIVAL){
        eventOrderFile << 
                totalEvents << ". Next event: Customer " << count << " Arrival" << endl;
    }else if(type == DEPARTURE){
        eventOrderFile << 
                totalEvents << ". Next event: Customer " << count << " Departure" << endl;
    }
}

void generateReportMSG(){
    double avgDelayInQ = delaySum / customerDelayedCount;
    double avgQlength = areaUnderQ / simulTime;
    double avgServerUtilization = areaUnderB / simulTime;


    resultFile << "----Single-Server Queueing System----\n" << endl;
    resultFile << "Mean inter-arrival time: " << A << " minutes" << endl;
    resultFile << "Mean service time: " << S << " minutes" << endl;
    resultFile << "Number of customers: " << N << endl;

    resultFile << endl;
    resultFile << "Avg delay in queue: " << delaySum / customerDelayedCount << " minutes" << endl;
    resultFile << "Average number in queue: " << areaUnderQ / simulTime << endl;
    resultFile << "Server utilization: " << areaUnderB / simulTime << endl;
    resultFile << "Time simulation ended: " << simulTime << " minutes" << endl;

}

#endif  