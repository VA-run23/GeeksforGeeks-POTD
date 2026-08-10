// High Effort vs Low Effort

/*
 *    1. The problem asks to maximize total tasks completed given two choices each day: high effort or low effort.
 *    2. High effort tasks cannot be chosen on consecutive days, while low effort tasks can be chosen freely.
 *    3. Use dynamic programming to track the best result up to each day.
 *    4. Maintain two states: prev1 (best result up to previous day) and prev2 (best result up to day before previous).
 *    5. Transition: choose low effort today → prev1 + l[i]; choose high effort today → prev2 + h[i].
 *    6. Current day’s best = max(lowChoice, highChoice).
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();

        int prev1 = max(h[0], l[0]);
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int lowChoice = prev1 + l[i];
            int highChoice = prev2 + h[i];
            int current = max(lowChoice, highChoice);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

// Key Points
// 1. Defines rules: high effort not consecutive, low effort allowed anytime.
// 2. Uses DP with rolling variables for efficiency.
// 3. prev1 tracks best result up to previous day.
// 4. prev2 tracks best result up to day before previous.
// 5. Transition considers both low and high effort choices.
// 6. Runs in O(n) time with O(1) space.
// 7. Elegant solution using iterative DP.