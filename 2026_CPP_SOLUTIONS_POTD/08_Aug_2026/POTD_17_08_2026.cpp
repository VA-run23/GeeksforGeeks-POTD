// Snake and Ladder Problem

/*
 *    1. The problem asks to find the minimum number of dice throws required to reach the last cell (n*n).
 *    2. Ladders move you forward, snakes move you backward.
 *    3. Build maps for ladders and snakes from the input arrays.
 *    4. Use BFS starting from cell 1, since BFS guarantees shortest path in unweighted graphs.
 *    5. For each position, simulate dice throws (1–6) to generate possible moves.
 *    6. If a move lands on a ladder or snake, adjust the position accordingly.
 *    7. Time Complexity: O(n²), Space Complexity: O(n²).
 */

class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        unordered_map<int, int> ladders;
        unordered_map<int, int> snacks;
        
        for (int i = 0; i + 1 < lad.size(); i += 2) {
            ladders[lad[i]] = lad[i + 1];
        }
        
        for (int i = 0; i + 1 < sn.size(); i += 2) {
            snacks[sn[i]] = sn[i + 1];
        }
        
        int ans = 0;
        queue<int> q;
        vector<bool> visited(n*n + 1, false);
        visited[1] = true;
        q.push(1);
        
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int curr = q.front();
                q.pop();
                
                if (curr == n*n) return ans;
                
                for (int i = 1; i <= 6; i++) {
                    int newNum = curr + i;
                    if (newNum > n*n) continue;
                    
                    if (ladders.count(newNum)) {
                        newNum = ladders[newNum];
                    } else if (snacks.count(newNum)) {
                        newNum = snacks[newNum];
                    }
                    
                    if (!visited[newNum]) {
                        q.push(newNum);
                        visited[newNum] = true;
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};

// Key Points
// 1. BFS ensures shortest path (minimum throws).
// 2. Maps ladders and snakes for quick lookup.
// 3. Each dice throw generates up to 6 possible moves.
// 4. Adjusts position if ladder or snake is encountered.
// 5. Tracks visited cells to avoid cycles.
// 6. Stops when reaching cell n*n.
// 7. Runs in O(n²) time with O(n²) space.