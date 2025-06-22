/* 
1. The input array is sorted in descending order so that we can check if smaller numbers divide larger ones.
2. We initialize a 'dp' array where dp[i] stores the length of the largest divisible subset ending at index i.
3. The 'older' array keeps track of the previous index in the subset chain for reconstruction.
4. We iterate over each pair (j, i) and update dp[i] if arr[j] % arr[i] == 0 and we get a longer subset by extending j to i.
5. We track the index of the element that ends the longest divisible subset using 'maxi'.
6. The subset is reconstructed by backtracking from maxi using the 'older' array and pushed into the result.
7. Time Complexity: O(n^2) for nested loops; Space Complexity: O(n) for dp and older arrays.
*/
class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        vector<int> dp(n, 1), older(n, -1);
        int maxi = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    older[i] = j;
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        
        vector<int> result;
        for (int i = maxi; i != -1; i = older[i]) {
            result.push_back(arr[i]);
        }
        return result;
    }
};::