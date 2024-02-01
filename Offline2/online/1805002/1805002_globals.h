#ifndef GLOBALS_H
#define GLOBALS_H

#include <bits/stdc++.h>
#include "RV_generator.h"

using namespace std;

#define ORDER_ARIVAL 1
#define DEMAND 2
#define END_OF_SIM 3
#define INV_CHECK 4
#define EXPRESS_ORDER 5


#define INF 1e+30

// -----Global variables-----
int isExpress = 1;
double I, N, P, D;
double beta_D;
double K, incr, h, pi, m, M;
int trialCount;
double E_K, E_i;
double E_m, E_M;
vector<double> cum_probabilities;
vector<pair<double, double>> policies;
double simulTime;

double nextEvenTime[6];
double currentInvLevel;

double timeLastEvent;
double currentOrderAmount;
int nextEventType;

double orderingCost;
double expressOrderingCost;
//double holdingCost;
//double backlogCost;

double areaUnderShortage;
double areaUnderHolding;


vector<double> avgTotalCost;
vector<double> avgTotalCostWithExpressOrder;
vector<double> avgOrderingCostPerPolicy;
vector<double> avgHoldingCostPerPolicy;
vector<double> avgShortageCostPerPolicy;

vector<double> trialAvgTotalCost;
vector<double> trialAvgTotalCostWithExpressOrder;
vector<double> trialAvgOrderingCostPerPolicy;
vector<double> trialAvgHoldingCostPerPolicy;
vector<double> trialAvgShortageCostPerPolicy;

// -----Global functions-----

double generateRandom(double mean){
    return -mean * log(lcgrand(1));
}

int getRandomDemandSize(){
    double rand = lcgrand(1); // U ~ U(0,1)
    int demandSizeSelected = 0;

    for(int i = 0; i < cum_probabilities.size(); i++){
        if(rand < cum_probabilities[i]){
            demandSizeSelected = i+1;
            break;
        }
    }

    return demandSizeSelected;
    
}

double uniformRV(double a, double b){
    return a + (b-a)*lcgrand(1);
}

void takeInput(ifstream &inputFile){
    inputFile >> trialCount;
    inputFile >> I >> N >> P;
    inputFile >> D >> beta_D;
    inputFile >> K >> incr >> h >> pi;
    inputFile >> E_K >> E_i;
    inputFile >> m >> M >> E_m >> E_M;
    cum_probabilities.resize(D);
    for(int i = 0; i < D; i++){
        inputFile >> cum_probabilities[i];
    }
    policies.resize(P);
    for(int i = 0; i < P; i++){
        inputFile >> policies[i].first >> policies[i].second;
    }
    
}

void updateAvgCosts(int policyIndex){
    double avgExpressOrderingCost = 0;
    double totalCostWithExpressOrder = 0;
    if (isExpress == 1)
        avgExpressOrderingCost = expressOrderingCost / N;
    double avgOrderingCost = orderingCost / N;
    double avgHoldingCost = h * areaUnderHolding / N;
    double avgShortageCost = pi * areaUnderShortage / N;
    double totalCost = avgOrderingCost + avgHoldingCost + avgShortageCost;
    
    if (isExpress == 1)
        totalCostWithExpressOrder = avgExpressOrderingCost + totalCost;
    
    avgTotalCost.push_back(totalCost);
    
    if (isExpress == 1)
        avgTotalCostWithExpressOrder.push_back(totalCostWithExpressOrder);
    
    
    avgOrderingCostPerPolicy.push_back(avgOrderingCost);
    avgHoldingCostPerPolicy.push_back(avgHoldingCost);
    avgShortageCostPerPolicy.push_back(avgShortageCost);
}

void updateTrialAvg(){
    //cout << "start updateTrialAvg" << endl;
    for(int i = 0; i < P; i++){
        trialAvgTotalCost[i] += avgTotalCost[i];
        //cout << "ok"  << endl;
        if (isExpress == 1)
            trialAvgTotalCostWithExpressOrder[i] += avgTotalCostWithExpressOrder[i];
        
        trialAvgOrderingCostPerPolicy[i] += avgOrderingCostPerPolicy[i];
        trialAvgHoldingCostPerPolicy[i] += avgHoldingCostPerPolicy[i];
        trialAvgShortageCostPerPolicy[i] += avgShortageCostPerPolicy[i];
    }
    //cout << "end updateTrialAvg" << endl;
}

void calculateTrialAvg(){
    for(int i = 0; i < P; i++){
        trialAvgTotalCost[i] /= trialCount;
        if (isExpress == 1)
            trialAvgTotalCostWithExpressOrder[i] /= trialCount;
        trialAvgOrderingCostPerPolicy[i] /= trialCount;
        trialAvgHoldingCostPerPolicy[i] /= trialCount;
        trialAvgShortageCostPerPolicy[i] /= trialCount;
    }
}


// -----Message Functions-----



void generateReport(ofstream &outputFile){
    
    outputFile << "------Single-Product Inventory System------\n" << endl;
    outputFile << "Initial inventory level: " << I << " items\n" << endl;
    outputFile << "Number of demand sizes: " << D << "\n" << endl;
    
    outputFile << "Distribution function of demand sizes: ";
    for(int i = 0; i < D; i++){
        // upto 2 decimal places
        outputFile <<  fixed << setprecision(2) << cum_probabilities[i] << " ";
    }
    outputFile << "\n" << endl;

    outputFile << "Mean inter-demand time: " << beta_D << " months\n" << endl;
    outputFile << "Delivery lag range: " << m << " to " << M << " months\n" << endl;
    outputFile << "Length of simulation: " << N << " months\n" << endl;

    outputFile << "Costs: " << endl;
    outputFile << "K = " << K << endl;
    outputFile << "i = " << incr << endl;
    outputFile << "h = " << h << endl;
    outputFile << "pi = " << pi << endl;
    outputFile << "\n" << endl;

    outputFile << "Number of policies: " << P << endl;
    outputFile << "Policies: " << endl;
    outputFile << "--------------------------------------------------------------------------------------------------" << endl;
    outputFile << " Policy        Avg_before_express     Avg_after_express      Avg_total_cost_with_express" << endl;
    outputFile << "--------------------------------------------------------------------------------------------------" << endl;
    for(int i=0; i<P; i++){
        outputFile << "(" << fixed << setprecision(0) << policies[i].first << ", " << policies[i].second << ")               " 
        << fixed << setprecision(2) << trialAvgTotalCost[i] << "               " << trialAvgTotalCostWithExpressOrder[i] << "               " 
        <<  endl;
        outputFile << endl;
    }
    outputFile << "--------------------------------------------------------------------------------------------------" << endl;


}



#endif  