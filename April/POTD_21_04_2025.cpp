/*
    This function finds the missing number in an array of size n containing integers from 1 to n+1 using XOR properties. 
    XORing all given numbers in arr is stored in xor1, and XORing numbers from 1 to n+1 is stored in xor2. 
    Since XOR of the same number cancels out, xor1 ^ xor2 leaves only the missing number. 
    This approach efficiently finds the missing number without extra space or sorting the array. 

    Time Complexity: O(N) - The function iterates through the array and another loop up to n+1, both taking linear time. 
    Space Complexity: O(1) - Only two integer variables (xor1, xor2) are used, requiring constant space. 
*/


class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xor1 = 0, xor2 = 0;
        
        for (int i = 0; i < n; i++) {
            xor1 ^= arr[i];
        }
        
        for (int i = 1; i <= n+1; i++) {
            xor2 ^= i;
        }
        
        return xor1 ^ xor2;
    }
};