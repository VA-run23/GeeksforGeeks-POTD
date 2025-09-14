/*
    1. This function finds the starting gas station index from which a car can complete a circular tour.
    2. It iterates through each station, accumulating total gas and total cost to check overall feasibility.
    3. 'currentGas' tracks the net fuel from the current candidate start station.
    4. If 'currentGas' drops below zero, the current start station is invalid, so we reset it to the next index.
    5. This works because if we can't reach station i+1 from the current start, none of the stations between start and i can be valid.
    6. After the loop, if totalGas is at least totalCost, the journey is possible from 'startIndex'; otherwise, return -1.
    7. Time Complexity: O(n), Space Complexity: O(1) — single pass with constant extra space.
*/

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