// Stable Marriage Problem

/*
 *    1. The problem requires finding a stable matching between men and women.
 *    2. Each man proposes to women in order of his preference list.
 *    3. Women rank men and decide based on their preference order.
 *    4. If a woman prefers her current partner, she rejects the new proposal.
 *    5. Free men continue proposing until they are matched.
 *    6. The algorithm ensures no unstable pair exists in the final matching.
 *    7. Time Complexity: O(n^2), Space Complexity: O(n^2)
 */

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();

        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        vector<int> man(n, -1), woman(n, -1), next(n, 0);
        vector<int> free;

        for (int i = 0; i < n; i++) free.push_back(i);

        while (!free.empty()) {
            int m = free.back();
            free.pop_back();

            int w = men[m][next[m]++];
            int curr = woman[w];

            if (curr == -1 || rank[w][m] < rank[w][curr]) {
                woman[w] = m;
                man[m] = w;

                if (curr != -1) free.push_back(curr);
            } else {
                free.push_back(m);
            }
        }

        return man;
    }
};

// Key Points
// 1. Implements Gale-Shapley algorithm for stable marriage.
// 2. Men propose sequentially to women based on preferences.
// 3. Women accept or reject proposals based on ranking.
// 4. Free men keep proposing until matched.
// 5. Women can switch partners if they prefer a new proposer.
// 6. Guarantees stability in final matching.
// 7. Runs efficiently with O(n^2) time complexity.