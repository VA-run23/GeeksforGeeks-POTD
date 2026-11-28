// Check if Path Exists Between Two Vertices

/*
 *    1. The problem asks to determine whether there is a path from vertex u to vertex v.
 *
 *    2. Represent the graph using the given adjacency list.
 *
 *    3. Use Depth First Search (DFS) iteratively with a stack.
 *       - Start traversal from vertex u.
 *
 *    4. Maintain a visited array to avoid processing the same vertex multiple times.
 *
 *    5. While traversing:
 *       - Pop a vertex from the stack.
 *       - If it equals v, a path exists.
 *
 *    6. Otherwise, push all unvisited adjacent vertices into the stack.
 *
 *    7. If traversal ends without reaching v, return false.
 *       Time Complexity: O(V + E), Space Complexity: O(V).
 */

class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here

        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> st;

        st.push(u);
        vis[u] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == v)
                return true;

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    st.push(nbr);
                }
            }
        }

        return false;
    }
};

// Key Points
// 1. Uses iterative DFS with a stack.
// 2. Starts traversal from source vertex u.
// 3. Visited array prevents revisiting nodes.
// 4. Returns true immediately upon reaching v.
// 5. Explores all reachable vertices from u.
// 6. If v is unreachable, returns false.
// 7. Runs in O(V + E) time with O(V) extra space.