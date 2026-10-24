// Trace Path - Matrix Operations 

/*
 *    1. The problem asks whether there exists a starting cell in an n × m matrix
 *       such that the entire movement sequence can be performed without leaving the grid.
 *
 *    2. Simulate the path assuming the starting position is (0, 0).
 *       Track the current coordinates (x, y) after every move.
 *
 *    3. Maintain four values:
 *       - minX = minimum horizontal position reached
 *       - maxX = maximum horizontal position reached
 *       - minY = minimum vertical position reached
 *       - maxY = maximum vertical position reached
 *
 *    4. For each move:
 *       - 'L' → x--
 *       - 'R' → x++
 *       - 'U' → y++
 *       - 'D' → y--
 *
 *    5. The path occupies a bounding rectangle whose:
 *       - Width  = maxX - minX + 1
 *       - Height = maxY - minY + 1
 *
 *    6. The movement sequence fits inside the matrix iff:
 *       - Width ≤ m
 *       - Height ≤ n
 *
 *    7. Time Complexity: O(|s|), Space Complexity: O(1).
 */

class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        int x = 0, y = 0;

        int minX = 0, maxX = 0;
        int minY = 0, maxY = 0;

        for (char ch : s) {
            if (ch == 'L') x--;
            else if (ch == 'R') x++;
            else if (ch == 'U') y++;
            else if (ch == 'D') y--;

            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }

        return (maxX - minX + 1 <= m) &&
               (maxY - minY + 1 <= n);
    }
};

// Key Points
// 1. Simulates the complete movement sequence.
// 2. Tracks minimum and maximum coordinates reached.
// 3. Forms the smallest bounding rectangle containing the path.
// 4. Width required = maxX - minX + 1.
// 5. Height required = maxY - minY + 1.
// 6. Path is valid only if the bounding rectangle fits in the matrix.
// 7. Runs in O(|s|) time with O(1) extra space.