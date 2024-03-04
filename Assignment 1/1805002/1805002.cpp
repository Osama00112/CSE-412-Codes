#include<bits/stdc++.h>
#include<iostream>
#include "1805002_globals.h"
#include "1805002_initialize.h"
#include "1805002_timing.h"
#include "1805002_events.h"

#define FILE_TYPE 3

string file1 = "IOs/io1/in.txt";
string file2 = "IOs/io2/in.txt";
string file3 = "IOs/io3/in.txt";


using namespace std;

void updateParams(){
    double interEventTime = simulTime - timeLastEvent;
    timeLastEvent = simulTime;

    areaUnderQ += currentQueueLength * interEventTime;
    areaUnderB += serverStatus * interEventTime;
}

int main(){
    switch(FILE_TYPE){
        case 1:
            inputFile.open(file1);
            break;
        case 2:
            inputFile.open(file2);
            break;
        case 3:
            inputFile.open(file3);
            break;
    }
    
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