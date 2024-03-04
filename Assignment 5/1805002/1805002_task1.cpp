#include<bits/stdc++.h>
#include "RV_generator.h"
#include "1805002_globals.h"
#include "1805002_initialize.h"

using namespace std;

ifstream inputFile;
ofstream outputFile;

string inputFilePath = "in_task1.txt";
string outputFilePath = "out_task1.txt";

int main(){
    inputFile.open(inputFilePath);
    outputFile.open(outputFilePath);
    
    takeInput(inputFile);

    vector<vector<int>> cum_neutron_freq;
    cum_neutron_freq = vector<vector<int>>(generationCount, vector<int>(5, 0));
    initialization_routine();

    for(int i = 0; i < trials; i++){
        // timing();
        int currentNeutronCount = 1;
        for (int j=0; j<generationCount; j++){
            int currentCount = currentNeutronCount;

            for(int k=0; k<currentCount; k++){
                int neutronCount = getRandomNeutronCount();
                currentNeutronCount += (neutronCount - 1);
            }

            if (currentNeutronCount <= 4)
                neutron_freq[j][currentNeutronCount] += 1;
            else if(currentNeutronCount < 0)
                cout << "error in neutron count\n";   
        }

        // for (int j=0; j<generationCount; j++)
        //     cum_neutron_freq[j][0] += neutron_freq[j][0];
    }

    for(int i = 0; i < generationCount; i++){
        outputFile << "Generation " << i+1 << ": " << endl;
        for(int j = 0; j < 5; j++){
            outputFile << "p[" << j << "] = " << (double)neutron_freq[i][j]/trials << endl;
        }
        outputFile << endl;
    }
    
    
    inputFile.close();
    outputFile.close();
    return 0;
}