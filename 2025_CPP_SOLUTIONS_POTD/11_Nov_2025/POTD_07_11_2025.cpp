/*
    1. Sort the jobs by their end time using a custom comparator to ensure we can apply binary search efficiently.
    2. Use dynamic programming (DP) where dp[i] stores the maximum profit achievable by scheduling jobs up to index i.
    3. For each job i, calculate the profit if we include it: jobs[i][2] + dp[l], where l is the last non-overlapping job found via binary search.
    4. The binarySearch function finds the rightmost job whose end time is ≤ the start time of the current job.
    5. Update dp[i] with the maximum of including the current job or excluding it (i.e., dp[i - 1]).
    6. Return dp[n - 1], which contains the maximum profit achievable with all jobs considered.
    7. Time Complexity: O(n log n) for sorting + O(n log n) for binary search per job → Total: O(n log n); Space Complexity: O(n) for the dp array.
*/

class Solution {
  public:
  
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; 
    }

    int binarySearch(vector<vector<int>>& jobs, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][1] <= jobs[index][0]) {
                if (jobs[mid + 1][1] <= jobs[index][0])
                    low = mid + 1;
                else
                    return mid;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(), jobs.end(), comp);
        int n = jobs.size();
        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; ++i) {
            int inclProfit = jobs[i][2];
            int l = binarySearch(jobs, i);
            if (l != -1) inclProfit += dp[l];
            dp[i] = max(inclProfit, dp[i - 1]);
        }

        return dp[n - 1];
    }
};
