// Equalize All Prefix Sums

/*
 *    1. We are given an array and need to construct an optimal array.
 *    2. The optimal array is built using prefix sums with adjustments.
 *    3. Each element depends on the previous result, current element, and half index element.
 *    4. Start with the first element as base case.
 *    5. Iteratively compute each next value using the recurrence relation.
 *    6. Store results in a separate vector and return it.
 *    7. Time Complexity: O(n), Space Complexity: O(n)
 */

class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        vector<int>res(1);
        for(int i=1;i<arr.size();i++){
            res.push_back(res[i-1]+arr[i]-arr[i/2]);
        }
        return res;
    }
};

// Key Points
// 1. Uses recurrence relation for efficient computation
// 2. Avoids recomputation of prefix sums
// 3. Relies on integer division for index halving
// 4. Builds result incrementally from base case
// 5. Maintains separate result vector
// 6. Linear time complexity ensures scalability
// 7. Space complexity proportional to input size