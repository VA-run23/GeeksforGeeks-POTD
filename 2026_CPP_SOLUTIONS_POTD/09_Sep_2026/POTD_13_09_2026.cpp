// Party in Town

/*
 *    1. The problem asks to find the minimum distance to the farthest house in a town (tree graph).
 *    2. This is equivalent to finding the tree’s radius.
 *    3. Approach:
 *       - Perform BFS from any node to find the farthest node (one end of diameter).
 *       - Perform BFS again from that farthest node to find the diameter length.
 *       - The radius = (diameter + 1) / 2.
 *    4. BFS tracks distances and finds farthest node efficiently.
 *    5. Return radius as the minimum distance required.
 *    6. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    pair<int, int> bfs(vector<vector<int>> &adj, int start) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        int farthestNode = start;
        int farthestDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : adj[node]) {
                next--; // adjust to 0-based index
                if (dist[next] == -1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);
                    if (dist[next] > farthestDist) {
                        farthestDist = dist[next];
                        farthestNode = next;
                    }
                }
            }
        }
        return {farthestNode, farthestDist};
    }

    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        pair<int, int> first = bfs(adj, 0);
        int diameterEnd = first.first;
        pair<int, int> second = bfs(adj, diameterEnd);
        int diameter = second.second;
        return (diameter + 1) / 2;
    }
};

// Key Points
// 1. Tree radius = (diameter + 1)/2.
// 2. BFS finds farthest node efficiently.
// 3. Two BFS runs compute diameter.
// 4. Adjust indices for 0-based arrays.
// 5. Answer is minimum distance to farthest house.
// 6. Runs in O(n) time with O(n) space.
// 7. Elegant use of BFS to solve tree radius problem.