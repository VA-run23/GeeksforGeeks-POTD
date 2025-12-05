/*
    1. The problem is to paint n walls with k colors such that no two adjacent walls have the same color, minimizing total cost.
    2. If k < 2 and n >= 2, it’s impossible to paint adjacent walls differently, so return -1.
    3. Initialize a DP table pk[n][k] where pk[i][j] stores the minimum cost to paint wall i with color j.
    4. Base case: pk[0][j] = costs[0][j] for all colors j of the first wall.
    5. For each wall i from 1 to n-1, find the minimum cost of the previous row (prevColor).
    6. For each color j: if j was the minimum in the previous row, use the second minimum; otherwise, add prevColor to costs[i][j].
    7. Finally, return the minimum value in pk[n-1], which represents the minimum cost to paint all walls.
    Time Complexity: O(n * k^2) due to repeated min_element calls inside loops.
    Space Complexity: O(n * k) for the DP table.
*/

class Solution {
  public:
    int minCost(vector<vector<int>>& costs) {
    // code here

    int n = costs.size();
    int k = costs[0].size();

    if (k < 2 && n >= 2) {
        return -1;
    }

    vector<vector<int>> pk(n, vector<int>(k, 0));

    for (int i = 0; i < k; i++) {
        pk[0][i] = (costs[0][i]);
    }

    if (n == 1) {
        return *min_element(pk[0].begin(), pk[0].end());
    }

    for (int i = 1; i < n; i++) {
        int prevColor = *min_element(pk[i - 1].begin(), pk[i - 1].end());

        for (int j = 0; j < k; j++) {
            if (prevColor == pk[i - 1][j]) {
                pk[i - 1][j] = INT_MAX;
                pk[i][j] = costs[i][j] +
                           *min_element(pk[i - 1].begin(), pk[i - 1].end());
                pk[i - 1][j] = prevColor;
            } else {
                pk[i][j] = costs[i][j] + prevColor;
            }
        }
    }

    return *min_element(pk[n - 1].begin(), pk[n - 1].end());
    }   
};