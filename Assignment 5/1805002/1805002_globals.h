#ifndef GLOBALS_H
#define GLOBALS_H

#include <bits/stdc++.h>
#include "RV_generator.h"

using namespace std;

#define INF 1e+30

// -----Global variables-----
int trials;
int generationCount;

int population;
int successCriteria;

vector<double> cum_probabilities;
double prob[4];
vector<vector<int>> neutron_freq;

double simulTime;
double nextEvenTime[5];
double timeLastEvent;
int nextEventType;

// -----Global functions-----

double generateRandom(double mean){
    return -mean * log(lcgrand(1));
}

int getRandomNeutronCount(){
    double rand = lcgrand(1); // U ~ U(0,1)
    int neutronCount = 0;

    for(int i = 0; i < cum_probabilities.size(); i++){
        if(rand < cum_probabilities[i]){
            neutronCount = i;
            break;
        }
    }

    return neutronCount;
}

double uniformRV(double a, double b){
    return a + (b-a)*lcgrand(1);
}

void takeInput(ifstream &inputFile){
    inputFile >> generationCount >> trials;
}

void takeInput_task2(ifstream &inputFile){
    inputFile >> population >> successCriteria ;
}


#endif  