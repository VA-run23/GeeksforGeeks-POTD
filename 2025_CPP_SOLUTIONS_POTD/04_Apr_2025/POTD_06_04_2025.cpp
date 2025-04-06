/*
    Topological Sorting using Kahn's Algorithm (BFS approach)

    1. Create an adjacency list (adj) and an in-degree array (inDeg)
    to store directed edges and count incoming edges for each node.
    2. Populate the adjacency list and update the in-degree of each node
    based on the directed edges provided in the edges list.
    3. Push all nodes with in-degree == 0 into the queue, as they have 
    no dependencies and can be processed first.
    4. Process nodes from the queue one by one, adding them to the result (ans) 
    and reducing the in-degree of their neighbors.
    5. Reduce the in-degree of adjacent nodes, and push them into the queue 
    once their in-degree becomes zero (i.e., free of dependencies).
    6. Return the final topological ordering (ans), ensuring that nodes 
    appear before their dependent nodes.
*/

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V]; 
        vector<int> inDeg(V, 0); 

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDeg[edge[1]]++;
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};