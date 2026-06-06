// Non-Attacking Black and White Knights

/*
 *    1. We need to count the number of ways to place two knights on an n x m board.
 *    2. Knights attack in an "L" shape, so we must exclude attacking pairs.
 *    3. First, calculate total possible pairs of knights.
 *    4. Then, count the number of attacking pairs using knight moves.
 *    5. Subtract attacking pairs from total pairs to get valid placements.
 *    6. Each attacking pair is counted twice, so adjust accordingly.
 *    7. Time Complexity: O(n*m), Space Complexity: O(1)
 */

class Solution {
public:
    int numOfWays(int n, int m) {
        // code here
        long long total = (long long)(n * m) * (n * m - 1);
        long long attacks = 0;
        int dx[] = {1, 2, 2, 1};
        int dy[] = {2, 1, -1, -2};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        attacks++;
                    }
                }
            }
        }
        return (int)(total - attacks * 2);
    }
};

// Key Points
// 1. Total pairs = n*m choose 2
// 2. Knights attack in 8 possible moves, but symmetry reduces to 4 directions
// 3. Count attacking pairs by iterating over all cells
// 4. Each attacking pair is double-counted, so multiply by 2
// 5. Subtract attacking pairs from total pairs
// 6. Efficient solution with O(n*m) complexity
// 7. Works for large boards due to constant space usage