// Largest Sum Cycle

/*
 *    1. The problem asks to find the cycle having the maximum sum of node values.
 *    2. The graph is represented using the given edge array where each node has at most one outgoing edge.
 *    3. Use DFS to traverse the graph while maintaining:
 *       - visited[] to avoid reprocessing nodes.
 *       - path[] to track nodes in the current DFS path.
 *    4. Store dist[node] as the cumulative sum of node values from the DFS starting point.
 *    5. When a node already present in the current path is encountered, a cycle is detected.
 *    6. Compute cycle sum as:
 *       sum - dist[cycleStart] + cycleStart.
 *       Update the maximum cycle sum found so far.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    vector<bool> visited, path;
    vector<int> dist;

    int ans = -1;

    void helper(int node, int sum) {
        path[node] = visited[node] = true;
        dist[node] = sum;

        for (auto &x : adj[node]) {
            if (!visited[x]) {
                helper(x, sum + x);
            }
            else if (path[x]) {
                ans = max(ans, sum - dist[x] + x);
            }
        }

        path[node] = false;
    }

    int largestSumCycle(vector<int>& edge) {

        int n = edge.size();

        adj.clear();

        for (int i = 0; i < n; i++) {
            if (edge[i] != -1)
                adj[i].push_back(edge[i]);
        }

        visited.assign(n, false);
        path.assign(n, false);
        dist.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                helper(i, i);
            }
        }

        return ans;
    }
};

// Key Points
// 1. Treats the edge array as a directed graph.
// 2. Each node has at most one outgoing edge.
// 3. DFS is used to detect cycles.
// 4. path[] identifies nodes currently in recursion stack.
// 5. dist[] stores cumulative node sums along DFS traversal.
// 6. Cycle sum is computed when a back-edge is found.
// 7. Runs in O(n) time with O(n) extra space.