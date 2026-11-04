// XOR of All Subarray XORs

/*
 *    1. The problem asks to find the XOR of XOR-values of all possible subarrays.
 *    2. Observe that each element arr[i] appears in:
 *       - (i + 1) choices of starting index.
 *       - (n - i) choices of ending index.
 *    3. Therefore, total occurrences of arr[i] across all subarrays:
 *       - cnt = (i + 1) * (n - i).
 *    4. In XOR operations:
 *       - An element contributes only if it appears an odd number of times.
 *       - Even occurrences cancel out.
 *    5. For each index, check whether cnt is odd.
 *    6. If cnt is odd, include arr[i] in the answer using XOR.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long cnt = 1LL * (i + 1) * (n - i);

            if (cnt % 2 == 1) {
                ans ^= arr[i];
            }
        }

        return ans;
    }
};

// Key Points
// 1. Counts how many subarrays contain each element.
// 2. Frequency of arr[i] = (i + 1) * (n - i).
// 3. XOR keeps only elements with odd occurrences.
// 4. Even occurrences cancel each other.
// 5. No need to generate subarrays explicitly.
// 6. Uses a single traversal of the array.
// 7. Runs in O(n) time with O(1) extra space.