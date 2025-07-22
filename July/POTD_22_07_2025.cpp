/* 
    1. Create a set 's' from the input vector 'arr' to store unique elements in sorted order.  
    2. Initialize 'expected' to 1, the smallest positive integer we aim to find.  
    3. Iterate through each number 'num' in the set 's'.  
    4. If 'num' equals 'expected', it means 'expected' is present, so increment 'expected'.  
    5. If 'num' is greater than 'expected', then 'expected' is missing—break early.  
    6. After the loop, return 'expected' as the smallest missing positive number.  
    7. Time Complexity: O(n log n) due to set insertion; Space Complexity: O(n) for the set.  
*/

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        set<int> s(arr.begin(), arr.end());
    
        int expected = 1; 
        for (int num : s) {
            if (num == expected) {
                expected++; 
            } else if (num > expected) {
                break;
            }
        }
    
        return expected;
    }
};