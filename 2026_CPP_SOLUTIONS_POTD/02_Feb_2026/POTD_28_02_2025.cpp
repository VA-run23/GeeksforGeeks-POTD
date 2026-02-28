/*
    1. This function finds a pair of numbers (one from each array) whose sum is closest to a given target x.
    2. It uses a two-pointer approach: one pointer starts at the beginning of arr1, the other at the end of arr2.
    3. At each step, it calculates the sum and checks how close it is to x, updating the best pair if needed.
    4. If the sum is less than x, the left pointer (i) is moved forward to increase the sum.
    5. If the sum is greater than or equal to x, the right pointer (j) is moved backward to decrease the sum.
    6. Time Complexity: O(n + m), since each pointer moves at most once across its array.
    7. Space Complexity: O(1), as only a few extra variables are used besides the input arrays.
*/

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        int i = 0; 
        int j = m - 1; 
        int prevDiff = INT_MAX;
        int val1 = -1;
        int val2 = -1;

        while (i < n && j >= 0) {
            int currentSum = arr1[i] + arr2[j];
            int currentDiff = abs(currentSum - x);

            if (currentDiff < prevDiff) {
                prevDiff = currentDiff;
                val1 = arr1[i];
                val2 = arr2[j];
            }

            if (currentSum < x) {
                i++;
            } else {
                j--;
            }
        }

        vector<int> ansList;
        ansList.push_back(val1);
        ansList.push_back(val2);

        return ansList;
    }
};

// Key points:
// - Two-pointer technique is used for efficiency.
// - One pointer moves forward, the other backward, balancing the sum toward x.
// - The algorithm ensures minimal difference between sum and target.
// - Time complexity is linear relative to array sizes.
// - Space usage is constant, making it memory-efficient.
// - Works best when arrays are sorted (assumed here).
// - Captures the closest pair without brute force checking all combinations.
