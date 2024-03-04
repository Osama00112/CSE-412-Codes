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

double servers, A, S, N;
// array of server status

vector<int> serverStatuses;


double simulTime;
double timeLastEvent;
double delaySum;
double areaUnderQ;
double areaUnderB;
double nextArrivalTime;
double nextDepartTime;

vector<double> nextDepartTimes;
int serverDepartureIndex;

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

void eventMSG(int totalEvents, int count, int type, int index){
    if(type == ARRIVAL){
        eventOrderFile << 
                totalEvents << ". Next event: Customer " << count << " Arrival" << endl;
    }else if(type == DEPARTURE){
        eventOrderFile << 
                totalEvents << ". Next event: Customer " << count << " Departure from server " << index+1 << endl;
    }
}

void generateReportMSG(){
    double avgDelayInQ = delaySum / customerDelayedCount;
    double avgQlength = areaUnderQ / simulTime;
    double avgServerUtilization = areaUnderB / simulTime;


    resultFile << "----Single-Server Queueing System----\n" << endl;
    resultFile << "Mean inter-arrival time: " << fixed << setprecision(6) <<  A << " minutes" << endl;
    resultFile << "Mean service time: " << S << " minutes" << endl;
    resultFile << "Number of customers: " << int(N) << endl;

    resultFile << endl;
    // with precision upto 6 decimal places 
    resultFile << "Avg delay in queue: " << delaySum / customerDelayedCount << " minutes" << endl;
    resultFile << "Avg number in queue: " << areaUnderQ / simulTime << endl;
    resultFile << "Server utilization: " << areaUnderB / simulTime << endl;
    resultFile << "Time simulation ended: " << simulTime << " minutes" << endl;

}

#endif  