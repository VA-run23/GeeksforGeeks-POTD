/*
1. The function `maxValue` determines the maximum sum of non-adjacent values from an input array `arr`.
2. If the array size is 1, it directly returns the only element as the result.
3. A helper lambda function `robLinear` is defined to compute the maximum sum for a linear array using dynamic programming.
4. `robLinear` keeps track of two variables, `prev1` (max sum till now) and `prev2` (max sum excluding the current element).
5. The input array `arr` is divided into two cases: `case1` excludes the last element, and `case2` excludes the first element.
6. The function calculates and returns the maximum value between the results of applying `robLinear` on `case1` and `case2`.
7. This approach efficiently solves the "House Robber II" problem for circular arrays by treating it as two linear sub-problems.
*/

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if (n == 1) return arr[0];
        
        auto robLinear = [](vector<int>& nums) {
            int prev1 = 0, prev2 = 0;
            for (int num : nums) {
                int temp = prev1;
                prev1 = max(prev2 + num, prev1);
                prev2 = temp;
            }
            return prev1;
        };
        
        vector<int> case1(arr.begin(), arr.end() - 1);
        vector<int> case2(arr.begin() + 1, arr.end());
        
        return max(robLinear(case1), robLinear(case2));
    }
};