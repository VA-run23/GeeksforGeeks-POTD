// Geek in a Maze

/*
 *    1. The problem asks to count how many cells Geek can visit starting from (r, c) with limited up and down moves.
 *    2. Movement rules: Geek can move left/right freely, but has limited up (u) and down (d) moves.
 *    3. Use BFS/0-1 BFS with a deque to explore cells efficiently.
 *    4. Track the best remaining up/down moves for each cell to avoid revisiting with worse states.
 *    5. When moving left/right, push to front (cost-free moves); when moving up/down, push to back (consumes moves).
 *    6. Only enqueue states if remaining moves are non-negative and better than previously recorded.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m).
 */

class Node {
public:
    int r, c, up, down;
    Node(int r, int c, int up, int down) {
        this->r = r;
        this->c = c;
        this->up = up;
        this->down = down;
    }
};

class Solution {
public:
    int X[4] = {-1, 1, 0, 0};
    int Y[4] = {0, 0, 1, -1};

    bool isValid(int i, int j, int n, int m, vector<vector<char>> &mat) {
        return (i >= 0 && j >= 0 && i < n && j < m && mat[i][j] == '.');
    }

    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (!isValid(r, c, n, m, mat)) return 0;

        vector<vector<pair<int, int>>> best(n, vector<pair<int, int>>(m, {-1, -1}));
        deque<Node*> dq;

        dq.push_front(new Node(r, c, u, d));
        best[r][c] = {u, d};

        while (!dq.empty()) {
            Node *cur = dq.front(); dq.pop_front();
            int ci = cur->r, cj = cur->c;

            for (int k = 0; k < 4; k++) {
                int ni = ci + X[k], nj = cj + Y[k];
                if (isValid(ni, nj, n, m, mat)) {
                    int cup = cur->up, cdown = cur->down;
                    if (k == 0) cup--;   // UP
                    if (k == 1) cdown--; // DOWN

                    if (cup >= 0 && cdown >= 0) {
                        if (cup > best[ni][nj].first || cdown > best[ni][nj].second) {
                            best[ni][nj] = {cup, cdown};
                            if (k >= 2) dq.push_front(new Node(ni, nj, cup, cdown)); // left/right
                            else dq.push_back(new Node(ni, nj, cup, cdown));         // up/down
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (best[i][j].first != -1) ans++;
            }
        }
        return ans;
    }
};

// Key Points
// 1. BFS/0-1 BFS ensures efficient exploration.
// 2. Tracks remaining up/down moves per cell.
// 3. Left/right moves are cost-free, pushed to front.
// 4. Up/down moves consume limits, pushed to back.
// 5. Avoids revisiting cells with worse states.
// 6. Counts all reachable cells with valid states.
// 7. Runs in O(n*m) time with O(n*m) space.