// Course Schedule I

/*
 *    1. We are given n courses and prerequisites as pairs.
 *    2. Each pair [a, b] means to take course a, you must first complete course b.
 *    3. The problem reduces to detecting cycles in a directed graph.
 *    4. If a cycle exists, it means courses cannot be completed.
 *    5. We build an adjacency list to represent dependencies.
 *    6. We use DFS with states (0 = unvisited, 1 = visiting, 2 = visited) to detect cycles.
 *    7. Time Complexity: O(n + m), Space Complexity: O(n + m), where m = number of prerequisites.
 */

class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> state(n, 0);  
        
        for (int i = 0; i < n; ++i) {
            if (state[i] != 0) continue;
            
            stack<pair<int, int>> st;  
            st.push({i, 0});
            state[i] = 1;
            
            while (!st.empty()) {
                auto& [node, idx] = st.top();
                
                if (idx == adj[node].size()) {
                    state[node] = 2;
                    st.pop();
                    continue;
                }
                
                int next = adj[node][idx++];
                
                if (state[next] == 1) return false;  
                if (state[next] == 0) {
                    state[next] = 1;
                    st.push({next, 0});
                }
            }
        }
        
        return true;
    }
};

// Key Points
// 1. The problem is essentially cycle detection in a directed graph.
// 2. Courses are nodes, prerequisites are directed edges.
// 3. If a cycle exists, not all courses can be finished.
// 4. DFS with state tracking helps detect cycles efficiently.
// 5. State array: 0 = unvisited, 1 = visiting, 2 = visited.
// 6. Stack-based DFS avoids recursion depth issues.
// 7. Complexity is linear in terms of courses and prerequisites.
