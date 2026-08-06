// Minimum Increment or Double Operations to Convert

/*
 *    1. The problem asks to find the minimum number of operations to convert an array to all zeros.
 *    2. Allowed operations are: subtract 1 from any element, or divide all elements by 2 simultaneously.
 *    3. To minimize operations, count total bit contributions (popcount) across all elements.
 *    4. Each set bit represents a required subtraction operation.
 *    5. Track the maximum element to determine how many division-by-2 operations are needed.
 *    6. Simulate reducing the maximum element to zero by repeated halving, counting division steps.
 *    7. Time Complexity: O(n · log(maxElement)), Space Complexity: O(1).
 */

class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        
        int maxElement = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        int reduceOp = 0;
        int divOp = 0;
        
        int temp = maxElement;
        
        for (auto i: arr){
            reduceOp += __builtin_popcount(i);
        }
        
        while (temp > 0){
            if (temp % 2 == 0){
                temp /= 2;
                divOp++;
            }
            else{
                temp -= 1;
            }
        }
        
        return reduceOp + divOp;
    }
};

// Key Points
// 1. Uses popcount to count all subtraction operations.
// 2. Tracks maximum element to determine division steps.
// 3. Each set bit requires a subtraction operation.
// 4. Division operations equal halving steps of max element.
// 5. Efficiently combines both operation types.
// 6. Runs in O(n log(maxElement)) time.
// 7. Uses constant space for computation.