// Minimum Squares with Full Cuts

/*
 * 1. Problem:
 *    - Given a rectangle of size n × m.
 *    - Find minimum number of squares required to tile the rectangle completely.
 *
 * 2. Approach:
 *    - Use recursive division based on Euclidean algorithm.
 *
 * 3. Base cases:
 *    - If n == 0 or m == 0 → return 0.
 *    - If n == 1 → return m (1×m rectangle needs m squares).
 *    - If m == 1 → return n (n×1 rectangle needs n squares).
 *
 * 4. Normalize dimensions:
 *    - Let mn = min(n, m).
 *    - Let mx = max(n, m).
 *
 * 5. Divide rectangle:
 *    - Place (mx / mn) squares of size mn × mn.
 *
 * 6. Recurse on remainder:
 *    - Remaining rectangle size = mn × (mx % mn).
 *    - Call minSquares(mn, mx % mn).
 *
 * 7. Final answer:
 *    - Total squares = (mx / mn) + recursive result.
 */

class Solution {
  public:
    int minSquares(int n, int m) {
        if (n == 0 || m == 0) return 0;
        if (n == 1) return m;
        if (m == 1) return n;

        int mn = min(n, m);
        int mx = max(n, m);

        int ans = (mx / mn) + minSquares(mn, mx % mn);
        return ans;
    }
};

// 🔑 Key Points
// - Uses Euclidean algorithm logic for rectangle tiling.
// - Each step places largest possible square.
// - Remainder rectangle handled recursively.
// - Base cases handle degenerate rectangles.
// - Time complexity: O(log(min(n, m))).
// - Space complexity: O(log(min(n, m))) recursion stack.
// - Efficient and elegant solution for large rectangles.