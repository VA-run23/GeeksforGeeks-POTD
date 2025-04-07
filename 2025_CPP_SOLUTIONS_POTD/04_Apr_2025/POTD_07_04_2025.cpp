/*
    1. Build adjacency list adj for the graph and initialize in-degree array indeg.
    2. Iterate through edges to populate adj and calculate in-degree for each vertex.
    3. Create a queue q and enqueue all vertices with zero in-degree, as they have no incoming edges.
    4. Use BFS-like approach: dequeue a vertex, increment visited node count, and update in-degrees of its neighbors.
    5. Push neighbors into the queue if their in-degree becomes zero after decrementing.
    6. After processing all vertices, compare visited node count with total vertices V.
    7. Return true if visited nodes are fewer than V, indicating a cycle in the graph.
*/


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indeg(V, 0);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indeg[i] == 0) q.push(i);

        int visNodes = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visNodes++;

            for (int neighbor : adj[node]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) q.push(neighbor);
            }
        }

        return visNodes != V;
    }
};