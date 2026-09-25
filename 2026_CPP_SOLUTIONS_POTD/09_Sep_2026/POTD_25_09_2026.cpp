// Box Stacking Problem (Recursive + Memoization)

/*
 *    1. Each box has dimensions: height, width, length.
 *    2. A box can be rotated → any dimension can be height, remaining two form base.
 *    3. Condition: A box can be placed on another only if both base dimensions are strictly smaller.
 *    4. Approach:
 *       - Generate all rotations for each box.
 *       - Normalize base dimensions (w ≤ l).
 *       - Sort boxes by base dimensions.
 *       - Use recursion + memoization:
 *         - solve(i) = max stack height ending at box i.
 *         - For each box j < i, if base[j] < base[i], try stacking.
 *    5. Answer = max(solve(i)) for all i.
 *    6. Time Complexity: O(n^2), Space Complexity: O(n).
 */

class Solution {
    static int solve(vector<vector<int>>& list, int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        int ans = list[i][2]; // height of current box
        for (int j = 0; j < i; j++) {
            if (list[j][0] < list[i][0] && list[j][1] < list[i][1]) {
                int stacked = list[i][2] + solve(list, j, dp);
                ans = max(ans, stacked);
            }
        }
        return dp[i] = ans;
    }

    static vector<vector<int>> allAreas(vector<int>& box) {
        return {
            {box[0], box[1], box[2]}, // original
            {box[1], box[2], box[0]}, // rotate
            {box[2], box[0], box[1]}  // rotate
        };
    }

public:
    static int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        int n = height.size();
        vector<vector<int>> boxes(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            boxes[i][0] = height[i];
            boxes[i][1] = width[i];
            boxes[i][2] = length[i];
        }

        // Step 1: Generate rotations
        vector<vector<int>> list;
        for (int i = 0; i < n; i++) {
            auto rotations = allAreas(boxes[i]);
            for (auto& p : rotations) {
                int w = min(p[0], p[1]);
                int l = max(p[0], p[1]);
                list.push_back({w, l, p[2]});
            }
        }

        // Step 2: Sort by base dimensions
        sort(list.begin(), list.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        // Step 3: DP with recursion
        vector<int> dp(list.size(), -1);
        int maxVal = 0;
        for (int i = 0; i < list.size(); i++) {
            maxVal = max(maxVal, solve(list, i, dp));
        }

        return maxVal;
    }
};

// Key Points
// 1. Generate all rotations for each box.
// 2. Normalize base dimensions (w ≤ l).
// 3. Sort boxes by base dimensions.
// 4. Recursively compute max stack height with memoization.
// 5. Answer = maximum stack height across all boxes.
// 6. Runs in O(n^2) time with O(n) space.