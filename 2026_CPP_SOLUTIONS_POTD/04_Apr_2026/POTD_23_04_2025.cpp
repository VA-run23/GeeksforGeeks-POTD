// Split an Array into Two Equal Sum Subarrays

/*
 *    1. Calculate the total sum of the array elements.
 *    2. If the total sum is odd, splitting into equal halves is impossible.
 *    3. Traverse the array while maintaining a running left sum.
 *    4. Simultaneously reduce the right sum by subtracting the current element.
 *    5. At each step, compare left sum and right sum.
 *    6. If they are equal, return true as the array can be split.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum % 2 == 1)return false;
        int leftSum = 0;
        for(int i = 0; i<arr.size(); i++){
            leftSum += arr[i];
            totalSum -= arr[i];
            if(leftSum == totalSum)return true;
        }
        
        return false;
    }
};

// Key Points
// 1. The total sum must be even for a valid split.
// 2. Running sums help avoid recomputation.
// 3. Left sum grows as we traverse the array.
// 4. Right sum shrinks simultaneously.
// 5. Equality check ensures balanced partition.
// 6. Early return improves efficiency.
// 7. Works in linear time with constant space.