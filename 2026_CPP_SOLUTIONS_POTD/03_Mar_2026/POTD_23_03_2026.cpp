// Length of Longest Cycle in a Graph

/*
 *    1. We are given a directed graph with V vertices and edges.
 *    2. Each node has at most one outgoing edge, forming chains or cycles.
 *    3. We need to find the length of the longest cycle present in the graph.
 *    4. Use a `next` array to store the single outgoing edge for each node.
 *    5. Traverse nodes with DFS-like exploration while tracking visit times.
 *    6. Detect cycles by checking if a node reappears in the current path.
 *    7. Time Complexity: O(V), Space Complexity: O(V) due to tracking arrays.
 */

class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> next(V, -1);
        for (auto &e : edges) {
            next[e[0]] = e[1];
        }
        
        vector<int> vis(V, 0);
        vector<int> time(V, 0);
        
        int timer = 1;
        int maxCycle = -1;
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            int node = i;
            unordered_map<int, int> mp;
            
            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                mp[node] = timer++;
                node = next[node];
            }
            
            if (node != -1 && mp.count(node)) {
                int cycleLen = timer - mp[node];
                maxCycle = max(maxCycle, cycleLen);
            }
        }
        
        return maxCycle;
    }
};

// Key Points
// 1. Each node has at most one outgoing edge.
// 2. Use `next` array to store outgoing edges.
// 3. Track visited nodes with `vis` array.
// 4. Use a map to record entry time of nodes.
// 5. Cycle detected if a node reappears in current path.
// 6. Length of cycle = current time - entry time.
// 7. Efficient O(V) solution using simple traversal.