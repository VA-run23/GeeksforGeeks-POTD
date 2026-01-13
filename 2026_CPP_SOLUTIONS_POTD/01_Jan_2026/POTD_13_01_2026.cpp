/*
   1. This function simulates a cashier serving customers who pay with 5, 10, or 20 units, starting with no change.
   2. It maintains two counters: cntFive (number of 5-unit bills) and cntTen (number of 10-unit bills).
   3. If a customer pays with 5, the cashier simply increases cntFive since no change is needed.
   4. If a customer pays with 10, the cashier must give back one 5; if available, cntFive decreases and cntTen increases, else return false.
   5. If a customer pays with 20, the cashier tries to give one 10 and one 5 (preferred), else three 5s; if neither is possible, return false.
   6. Any other denomination leads to immediate failure, ensuring only 5, 10, and 20 are valid inputs.
   7. If the loop completes successfully, return true, meaning all customers were served correctly.
      Time Complexity: O(n), where n = arr.size(), since each customer is processed once.
      Space Complexity: O(1), as only two counters are used regardless of input size.
*/

// Key Points:
// - Greedy approach: always prefer giving one 10 + one 5 for 20, as it preserves smaller bills.
// - Ensures correct change distribution at each step.
// - Efficient: linear time, constant space.

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int cntFive = 0;
        int cntTen = 0;
        
        for ( int i = 0; i < arr.size(); i++){

            if(arr[i] == 5) {
                cntFive++;
            }
            
            else if(arr[i] == 10){
                if(cntFive > 0){
                    cntFive--; 
                    cntTen++; 
                }else{ 
                    return false;
                }
            } 
            else if(arr[i] == 20){
                if(cntFive > 0 && cntTen > 0){
                    cntTen--; 
                    cntFive--;
                }else if(cntFive >= 3){ 
                    cntFive -= 3;
                }else{
                    return false;
                }
            } else{ 
                return false;
            }
        }
        return true;
    }
};