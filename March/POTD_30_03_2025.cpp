/*
    1. Initialize variables to track total gas, total cost, current gas in the tank, and the starting index of the station.
    2. Iterate through each gas station in the given vector, summing total gas and total cost, and calculating current gas after visiting each station.
    3. If `currentGas` drops below zero, it means the journey cannot continue from the current station, so update `startIndex` to the next station.
    4. Reset `currentGas` to zero since the journey is restarted from the updated `startIndex`.
    5. After processing all stations, check if the total gas is sufficient to cover the total cost of the journey.
    6. If total gas is greater than or equal to total cost, return `startIndex` as the station from where the journey can successfully start.
    7. If total gas is less than total cost, return -1, indicating that completing the journey is impossible.
*/

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;
           for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                startIndex = i + 1; 
                currentGas = 0;    
            }
        }


        return (totalGas >= totalCost) ? startIndex : -1;
    }
};