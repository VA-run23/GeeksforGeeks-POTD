// Maximum Difference of Zeros and Ones in Binary String

/*
 *    1. The problem asks for the maximum difference between count of '0's and '1's in any substring.
 *    2. Treat '0' as +1 and '1' as -1 to convert the problem into a maximum subarray sum problem.
 *    3. Use Kadane’s algorithm to track the maximum sum of such a transformed array.
 *    4. Maintain a running sum and reset it to 0 if it becomes negative.
 *    5. Update the maximum sum encountered during traversal.
 *    6. Return the maximum sum as the answer, or -1 if no valid substring exists.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int currSum = 0;
        int maxSum = -1;
        
        for(char ch : s) {
            if(ch == '0')
                currSum++;
            else 
                currSum--;
            
            maxSum = max(currSum, maxSum);
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};

// Key Points
// 1. Convert binary string into numeric values (+1 for '0', -1 for '1').
// 2. Problem reduces to finding maximum subarray sum.
// 3. Kadane’s algorithm is the optimal approach.
// 4. Reset running sum when it drops below zero.
// 5. Keep track of maximum sum throughout traversal.
// 6. Answer represents maximum difference between zeros and ones.
// 7. Efficient solution with O(n) time and O(1) space.