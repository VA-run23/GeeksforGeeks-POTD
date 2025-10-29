/*
    1. This code computes the diameter of a tree (an undirected, connected, acyclic graph) using two DFS traversals.
    2. The first DFS starts from node 0 and finds the farthest node from it, storing that node in `farthestNode`.
    3. The second DFS starts from `farthestNode` and finds the maximum distance to any other node — this is the diameter.
    4. The adjacency list `adj` is built from the input edge list to represent the graph efficiently.
    5. The `dfs` function recursively explores each node, updating `maxDist` and `farthestNode` when a longer path is found.
    6. Time Complexity: O(V), since each node is visited once per DFS and there are two DFS calls.
    7. Space Complexity: O(V) for the adjacency list and visited arrays used in each DFS.
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int dist, int& maxDist, int& farthestNode) {
        vis[node] = true;
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, dist + 1, maxDist, farthestNode);
            }
        }
    }

    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int farthestNode = 0, maxDist = 0;
        vector<bool> vis1(V, false);
        dfs(0, adj, vis1, 0, maxDist, farthestNode);  
        maxDist = 0;
        vector<bool> vis2(V, false);
        dfs(farthestNode, adj, vis2, 0, maxDist, farthestNode);  

        return maxDist;
    }
};