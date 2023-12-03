#include<bits/stdc++.h>
#include<iostream>
#include "1805002_globals.h"
#include "1805002_initialize.h"
#include "1805002_timing.h"
#include"RV_generator.h"

#define BUSY 1
#define IDLE 0
#define QueueLim 100
#define INF 1e+30

using namespace std;

// double A, S, N;
// double simulTime, timeLastEvent, delaySum, areaUnderQ, areaUnderB, nextArrivalTime, nextDepartTime;
// int serverStatus, customerDelayedCount, currentQueueLength;
// vector<double> arrivalTimes;

// void initialization_routine(){
//     simulTime = 0;
//     serverStatus = IDLE;
//     timeLastEvent = 0;

//     delaySum = 0;
//     customerDelayedCount = 0;
//     currentQueueLength = 0;
//     areaUnderQ = 0;
//     areaUnderB = 0;
//     timeLastEvent = 0;

//     nextArrivalTime = generateRandom(A);
//     nextDepartTime = INF;
// }

void updateParams(){
    double interEventTime = simulTime - timeLastEvent;
    timeLastEvent = simulTime;

    areaUnderQ += currentQueueLength * interEventTime;
    areaUnderB += serverStatus * interEventTime;
}

void generateReport(){

}

// void arrival(){
//     double delay;
//     nextArrivalTime = simulTime + generateRandom(A);


//     if(serverStatus == IDLE){
//         delay = 0;
//         customerDelayedCount++;
//         serverStatus = BUSY;
//         nextDepartTime = simulTime + generateRandom(S);

//     }else{
//         currentQueueLength++;
//         if(currentQueueLength > QueueLim){
//             cout << "Queue Limit Exceeded" << endl;
//             exit(2); 
//         }

//         arrivalTimes.push_back(simulTime);
//     }
// }

// void departure(){
//     double delay;

//     if(currentQueueLength == 0){
//         serverStatus = IDLE;
//         nextDepartTime = INF;
//     }else{
//         currentQueueLength--;
//         delay = simulTime - arrivalTimes[0];
//         delaySum += delay;
//         customerDelayedCount++;
//         nextDepartTime = simulTime + generateRandom(S);
//         arrivalTimes.erase(arrivalTimes.begin());
//     }

// }

int main(){
    inputFile.open("IOs/io1/in.txt");
    eventOrderFile.open("event_orders.txt");
    resultFile.open("results.txt");

    
    inputFile >> A >> S >> N;
    eventOrderFile << "A: " << A << " S: " << S << " N: " << N << endl;

    initialization_routine();

    int totalEvents = 0;
    int customerArrivalCount = 0;
    int customerDepartureCount = 0;

    while(customerDelayedCount < N){
        timing_routine();
        updateParams();

        if(nextEventType == ARRIVAL){
            arrival();
            totalEvents++;
            customerArrivalCount++;
            eventMSG(totalEvents, customerArrivalCount, ARRIVAL);
        }else{
            departure();
            totalEvents++;
            customerDepartureCount++;
            eventMSG(totalEvents, customerDepartureCount, DEPARTURE);
        }
    }

    

    return 0;
}