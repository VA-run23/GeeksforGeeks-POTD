// Your Social Network

/*
 * 1. Problem:
 *    - You are given a parent array describing a rooted tree (root = 1).
 *    - For each node i, find its distance to all ancestors.
 *
 * 2. Build network:
 *    - For each node i (2 to n), trace path back to root.
 *
 * 3. Track distances:
 *    - Maintain dist[] array to store distance from i to each ancestor.
 *
 * 4. Traverse upwards:
 *    - Start at i, move to parent until reaching root.
 *    - Increment distance at each step.
 *
 * 5. Record connections:
 *    - For each ancestor j encountered, store {i, j, dist[j]}.
 *
 * 6. Collect results:
 *    - Push all valid triples into answer vector.
 *
 * 7. Final answer:
 *    - Return list of triples representing social network connections.
 */

class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<vector<int>> ans;

        // Step 1: For each node i
        for (int i = 2; i <= n; i++) {
            vector<int> dist(i + 1, 0);
            int curr = i, k = 0;

            // Step 2: Traverse upwards to root
            while (curr != 1) {
                curr = arr[curr - 2]; // parent
                k++;
                dist[curr] = k;
            }

            // Step 3: Record connections
            for (int j = 1; j < i; j++) {
                if (dist[j] != 0) {
                    ans.push_back({i, j, dist[j]});
                }
            }
        }
        return ans;
    }
};

// 🔑 Key Points
// - Input arr defines parent-child relationships in a rooted tree.
// - For each node, trace path to root.
// - Distance increments by 1 at each step upward.
// - Store triples {child, ancestor, distance}.
// - Works for all nodes from 2 to n.
// - Time complexity: O(n^2) in worst case.
// - Space complexity: O(n) for dist array per node.