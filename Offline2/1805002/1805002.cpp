#include<bits/stdc++.h>
#include "RV_generator.h"
#include "1805002_globals.h"
#include "1805002_initialize.h"
#include "1805002_timing.h"
#include "1805002_events.h"


using namespace std;

ifstream inputFile;
ofstream outputFile;

string inputFilePath = "io1/in.txt";
string outputFilePath = "out.txt";

int main(){
    inputFile.open(inputFilePath);
    outputFile.open(outputFilePath);
    
    takeInput(inputFile);

    // avgTotalCost.resize(P);
    // avgOrderingCostPerPolicy.resize(P);
    // avgHoldingCostPerPolicy.resize(P);
    
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
            else{
                cout << "Error. Undefined next event type" << endl;
                exit(1);
            }
        }

        updateAvgCosts(i);
        //cout << "Policy " << i+1 << " updated" << endl;
    }


    generateReport(outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}