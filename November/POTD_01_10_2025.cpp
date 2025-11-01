/*
    1. This code solves the Course Schedule II problem using Kahn's Algorithm (BFS-based Topological Sort).
    2. It builds an adjacency list `adj` to represent course dependencies and an `indeg` array to track incoming edges.
    3. Courses with zero prerequisites (indegree 0) are pushed into a queue to start the topological sort.
    4. While the queue is not empty, it processes each course, adds it to the result `order`, and reduces indegree of its neighbors.
    5. If any neighbor's indegree becomes zero, it is added to the queue for processing.
    6. After processing all nodes, if the size of `order` equals `n`, a valid course order is returned; otherwise, a cycle exists and an empty list is returned.
    7. Time Complexity: O(n + m), where n = number of courses and m = number of prerequisites; Space Complexity: O(n + m) for adjacency list and indegree array.
*/

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        
        queue<int> q;
        vector<int> order;
        
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for (int nbr : adj[node]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) q.push(nbr);
            }
        }
        
        if (order.size() == n) return order;
        return {}; 
    }
};