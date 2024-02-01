#include<bits/stdc++.h>
#include "RV_generator.h"
#include "1805002_globals.h"
#include "1805002_initialize.h"
#include "1805002_timing.h"
#include "1805002_events.h"


using namespace std;

ifstream inputFile;
ofstream outputFile;

string inputFilePath = "IOs/io1/in.txt";
string outputFilePath = "out.txt";

int main(){
    inputFile.open(inputFilePath);
    outputFile.open(outputFilePath);
    
    takeInput(inputFile);
    //trialCount = 1;

    // avgTotalCost.resize(P);
    // avgOrderingCostPerPolicy.resize(P);
    // avgHoldingCostPerPolicy.resize(P);
    
    trialAvgTotalCost.resize(P);
    trialAvgTotalCostWithExpressOrder.resize(P);
    trialAvgOrderingCostPerPolicy.resize(P);
    trialAvgHoldingCostPerPolicy.resize(P);
    trialAvgShortageCostPerPolicy.resize(P);

    //with Express
    isExpress = 1;
    for(int t=0; t<trialCount; t++){
        //cout << "Trial " << t+1 << endl;
        trialInitialize();
        for (int i=0; i<P; i++){
            initialization_routine();
            
            //cout << "Policy " << i+1 << ": " << policies[i].first << " " << policies[i].second << endl;

            while(true){
                // if (simulTime > 119)
                //     cout << "SimulTime: " << simulTime << endl;
                timing_routine();
                calculateStats();
                
                if(nextEventType == END_OF_SIM){
                    break;
                }
                
                if (nextEventType == ORDER_ARIVAL){
                    order_arrival_routine();
                }
                else if (nextEventType == DEMAND){
                    demand_routine();
                }
                else if (nextEventType == INV_CHECK){
                    inv_check_routine(i);
                }
                else if (nextEventType == EXPRESS_ORDER){
                    express_order_routine();
                }
                else{
                    cout << "Error. Undefined next event type" << endl;
                    exit(1);
                }
            }

            updateAvgCosts(i);
            //cout << "Policy " << i+1 << " updated" << endl;
            
        }

        updateTrialAvg();
    }

    
    // no express
    //isExpress = 0;
    // for(int t=0; t<trialCount; t++){

    //     trialInitialize();
    //     for (int i=0; i<P; i++){
    //         initialization_routine();
            
    //         //cout << "Policy " << i+1 << ": " << policies[i].first << " " << policies[i].second << endl;

    //         while(true){
    //             // if (simulTime > 119)
    //             //     cout << "SimulTime: " << simulTime << endl;
    //             timing_routine();
    //             calculateStats();
                
    //             if(nextEventType == END_OF_SIM){
    //                 break;
    //             }
                
    //             if (nextEventType == ORDER_ARIVAL){
    //                 order_arrival_routine();
    //             }
    //             else if (nextEventType == DEMAND){
    //                 demand_routine();
    //             }
    //             else if (nextEventType == INV_CHECK){
    //                 inv_check_routine(i);
    //             }
    //             // else if (nextEventType == EXPRESS_ORDER){
    //             //     express_order_routine();
    //             // }
    //             else{
    //                 cout << "Error. Undefined next event type" << endl;
    //                 exit(1);
    //             }
    //         }

    //         updateAvgCosts(i);
    //         //cout << "Policy " << i+1 << " updated" << endl;
    //     }

    //     updateTrialAvg();
    // }


    calculateTrialAvg();


    generateReport(outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}