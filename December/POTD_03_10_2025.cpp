/*
    1. This code solves the Travelling Salesman Problem (TSP) using Dynamic Programming with bitmasking.
    2. 'n' is the number of cities, and 'N = 1 << n' represents all possible subsets of visited cities.
    3. 'dp[mask][i]' stores the minimum cost to reach city 'i' having visited the set of cities represented by 'mask'.
    4. Initialization: 'dp[1][0] = 0' means starting at city 0 with only city 0 visited.
    5. Transition: For each state '(mask, i)', try visiting an unvisited city 'j' and update 'dp[newMask][j]'.
    6. After filling the DP table, compute the minimum cost of completing the tour by returning to city 0 from any city.
    7. Time Complexity: O(n^2 * 2^n), Space Complexity: O(n * 2^n).
*/

// Key Points:
// - Uses bitmasking to represent visited cities efficiently.
// - Dynamic Programming ensures overlapping subproblems are solved once.
// - The final loop checks all possible last cities before returning to the start.
// - Guarantees optimal solution for TSP but only feasible for small n (≈20).

class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // code here
        
        int n = cost.size();
        int N = 1 << n;
        int ans = INT_MAX;
        vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
    
        for (int mask = 0; mask < N; mask++) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] == INT_MAX)
                    continue;
    
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j))
                        continue;
                    int newMask = mask | (1 << j);
                    dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
    
        int fullmask = N - 1;
        for (int j = 1; j < n; j++) {
            ans = min(ans, dp[fullmask][j] + cost[j][0]);
        }
        
        return ans == INT_MAX ? 0 : ans;
        
    }
};