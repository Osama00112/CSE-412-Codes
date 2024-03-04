#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <bits/stdc++.h>
#include "1805002_globals.h"

void initialization_routine(){
    for (int i = 1; i <= 3; i++){
        prob[i] = 0.2126* pow(0.5893, i-1);
    }
    prob[0] = 1 - prob[1] - prob[2] - prob[3];

    cum_probabilities.push_back(prob[0]);
    for(int i = 1; i <= 3; i++){
        cum_probabilities.push_back(cum_probabilities[i-1] + prob[i]);
    }
    neutron_freq = vector<vector<int>>(generationCount, vector<int>(5, 0));
    simulTime = 0;
    timeLastEvent = 0;
}

#endif
