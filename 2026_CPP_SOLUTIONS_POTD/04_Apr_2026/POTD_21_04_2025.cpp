// Two Water Jug Problem

/*
 *    1. We are given two jugs with capacities m and n.
 *    2. The task is to measure exactly d liters using these jugs.
 *    3. We can perform operations like filling, emptying, or pouring between jugs.
 *    4. The gcd of m and n must divide d for a solution to exist.
 *    5. If d is greater than the maximum of m and n, it is impossible.
 *    6. We simulate the process using helper functions for both jug orders.
 *    7. Time Complexity: O(d), Space Complexity: O(1).
 */

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return b == 0 ? a : gcd(b, a % b);
    }

    int helper(int full, int half, int d) {
        int bot1 = full, bot2 = 0, step = 1;
        while (bot1 != d && bot2 != d) {
            if (bot1 == 0) {
                bot1 = full;
                step++;
            }
            int po = min(bot1, half - bot2);
            bot2 += po;
            bot1 -= po;
            step++;
            if (bot1 == d || bot2 == d)
                break;
            if (bot1 == 0) {
                bot1 = full;
                step++;
            }
            if (bot2 == half) {
                bot2 = 0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d) {
        // Code here
        if (d > max(m, n))
            return -1;
        if (d % gcd(m, n) != 0)
            return -1;
        return min(helper(m, n, d), helper(n, m, d));
    }
};

// Key Points
// 1. The problem is based on the classic water jug puzzle.
// 2. gcd(m, n) must divide d for a valid solution.
// 3. If d > max(m, n), no solution exists.
// 4. Simulation is done by pouring between jugs step by step.
// 5. Both jug orders (m→n and n→m) must be checked.
// 6. The minimum steps from both simulations is the answer.
// 7. Efficient solution with O(d) time and O(1) space.