#include<bits/stdc++.h>
#include<iostream>
#include "1805002_globals.h"
#include "1805002_initialize.h"
#include "1805002_timing.h"
#include "1805002_events.h"

using namespace std;

void updateParams(){
    double interEventTime = simulTime - timeLastEvent;
    timeLastEvent = simulTime;

    areaUnderQ += currentQueueLength * interEventTime;
    areaUnderB += serverStatus * interEventTime;
}

int main(){
    inputFile.open("IOs/io2/in.txt");
    eventOrderFile.open("event_orders.txt");
    resultFile.open("results.txt");

    inputFile >> A >> S >> N;
    //eventOrderFile << "A: " << A << " S: " << S << " N: " << N << endl;

    initialization_routine();
    
    while(customerDelayedCount < N){
        timing_routine();
        updateParams();
        totalEvents++;

        if(nextEventType == ARRIVAL){
            arrival();
        }else{
            departure();
        }
    }

    generateReportMSG();

    inputFile.close();
    eventOrderFile.close();
    resultFile.close();

    return 0;
}