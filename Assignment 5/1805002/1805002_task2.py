import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

np.random.seed(0)
trials = 20000

inputFile = 'in_task2.txt'
outputFile = 'out_task2.txt'

# take population and successs criteria from input file
with open(inputFile, 'r') as f:
    # split by space
    data = f.read().split()
    population = int(data[0])
    success = int(data[1])

print('Population:', population)
print('Success:', success)

# population = 100
# success = 7


# random shuffle of population
def shuffle(population):
    np.random.shuffle(population)
    return population


success_count = []
# initialize success count
for i in range(population+1):
    success_count.append(0)

for t in range(trials):
    suffledPopulation = shuffle(list(range(1, population+1)))
    #print('Suffled Population:', suffledPopulation)
    
    for m in range(population+1):
        # take m samples from suffled population
        if m == 0:
            if suffledPopulation[0] <= success:
                success_count[m] = success_count[m] + 1
            continue
        
        samples = suffledPopulation[:m]
        
        # best rank of samples
        bestRank = min(samples)
        #print('Best Rank:', bestRank)
        
        choosen_rank = 0
        # check sequentially from other samples
        for i in range(m, len(suffledPopulation)):
            if suffledPopulation[i] < bestRank:
                choosen_rank = suffledPopulation[i]
                break
        if choosen_rank == 0:
            choosen_rank = suffledPopulation[m-1]
            
        # print('Choosen Rank:', choosen_rank)
        
        if choosen_rank <= success:
            success_count[m] = success_count[m] + 1
            
        


# divide success count by number of trials
success_rate = np.array(success_count) / trials

# plot success rate vs m
plt.plot(range(1, population+2), success_rate)
plt.xlabel('m')
plt.ylabel('Success Rate')
plt.ylim(0, 1)
plt.title(f'Success Rate vs m \n[n={population}, s={success}]')
plt.savefig(f'plots/n{population}_s{success}.png')
plt.show()



# optimal m
optimal_m = np.argmax(success_rate)
print('Optimal m:', optimal_m, " = ", (optimal_m/population)*100, '%')





