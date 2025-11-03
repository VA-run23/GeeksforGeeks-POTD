/*
    1. Constructs the graph and its reverse using adjacency lists, while tracking out-degrees of each node.
    2. Identifies terminal nodes (with out-degree 0) and adds them to a queue for reverse BFS traversal.
    3. Performs reverse BFS: for each safe node, reduces out-degree of its predecessors in the reverse graph.
    4. If a predecessor’s out-degree becomes 0, it’s marked safe and added to the queue.
    5. After traversal, all nodes marked visited are safe and collected into the result vector.
    6. Sorts the safe nodes to return them in ascending order as required.
    7. Time Complexity: O(V + E); Space Complexity: O(V + E) — efficient for large graphs.
*/

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here

        vector<vector<int>> graph(V);
        vector<vector<int>> revGraph(V);
        vector<int> outdeg(V, 0);
        vector<int> safe;
        queue<int> q;

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            outdeg[edge[0]]++;
            revGraph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < V; i++) {
            if (outdeg[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> visited(V, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            for (int prev : revGraph[node]) {
                outdeg[prev]--;
                if (outdeg[prev] == 0 && !visited[prev]) {
                    q.push(prev);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (visited[i]) safe.push_back(i);
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};