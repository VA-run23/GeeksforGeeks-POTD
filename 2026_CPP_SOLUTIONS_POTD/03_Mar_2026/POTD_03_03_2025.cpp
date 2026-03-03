/*
    1. This function finds the longest subarray containing at most two distinct elements.  
    2. It uses a sliding window approach with two pointers (i and j).  
    3. An unordered_map tracks the frequency of elements inside the current window.  
    4. If more than two distinct elements are present, the left pointer (i) is moved forward until only two remain.  
    5. At each step, the maximum window size (mx) is updated with j - i + 1.  
    6. Time Complexity: O(n), since each element is processed at most twice (once by j, once by i).  
    7. Space Complexity: O(2) ≈ O(1), as the map holds at most two distinct elements.  
*/

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int mx = INT_MIN;

        while (j < n) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }

        return mx;
    }
};

// Key points:
// - Sliding window ensures efficient traversal without re-checking subarrays.
// - The unordered_map maintains counts of elements in the current window.
// - Shrinking the window when >2 distinct elements ensures validity.
// - The maximum length is updated dynamically as the window expands/contracts.
// - Optimal because each element is visited at most twice.
// - Time complexity is linear, space complexity is constant.
// - This approach balances simplicity and efficiency for the problem.