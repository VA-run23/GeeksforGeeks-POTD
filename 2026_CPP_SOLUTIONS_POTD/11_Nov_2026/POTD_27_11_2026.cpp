// Count Edges in an Undirected Graph

/*
 *    1. The problem asks to find the total number of edges in an undirected graph.
 *
 *    2. The graph is represented using an adjacency list.
 *
 *    3. In an undirected graph, every edge (u, v) appears twice:
 *       - Once in u's adjacency list.
 *       - Once in v's adjacency list.
 *
 *    4. Traverse all adjacency lists and count the total number of entries.
 *
 *    5. Let this count be res.
 *       - res = 2 × (number of edges).
 *
 *    6. Divide the total count by 2 to remove double counting.
 *
 *    7. Time Complexity: O(V + E), Space Complexity: O(1).
 */

class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here

        int res = 0;

        for (auto vec : adj)
            res += vec.size();

        return res / 2;
    }
};

// Key Points
// 1. Uses adjacency list representation of the graph.
// 2. Each undirected edge appears twice.
// 3. Counts all adjacency list entries.
// 4. Divides by 2 to get actual edge count.
// 5. No extra data structures are required.
// 6. Simple graph traversal approach.
// 7. Runs in O(V + E) time with O(1) extra space.