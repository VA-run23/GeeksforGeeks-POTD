// Minimum Height Roots

/*
 *    1. The problem is to find all possible root nodes that yield minimum height trees.
 *    2. A tree’s height depends on the longest path from the root to a leaf.
 *    3. The optimal roots are essentially the centroids of the tree.
 *    4. Centroids can be found by iteratively removing leaf nodes.
 *    5. Continue pruning until only 1 or 2 nodes remain.
 *    6. These remaining nodes are the minimum height roots.
 *    7. Time Complexity: O(V) and Space Complexity: O(V) where V is the number of vertices.
 */

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        int count[100001] = {0};
        vector<vector<int>> v(V);
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
            count[a]++;
            count[b]++;
        }

        queue<int> q;
        for(int i = 0;i<V;i++){
            if(count[i] == 1){
                q.push(i);
            }
        }
        int rem = V;
        while(rem > 2){
            int b = q.size();
            int c = q.size();
            while(b--){
                int a = q.front();
                q.pop();
                vector<int> w = v[a];
                for(int i = 0;i<w.size();i++){
                    count[w[i]]--;
                    if(count[w[i]] == 1){
                        q.push(w[i]);
                    }
                }
            }
            rem -= c;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

// Key Points
// 1. The problem reduces to finding centroids of the tree.
// 2. Centroids are nodes that minimize the maximum distance to all other nodes.
// 3. Iterative leaf removal is the standard approach.
// 4. At most two centroids exist in any tree.
// 5. BFS/queue is used to simulate pruning leaves layer by layer.
// 6. The algorithm ensures linear time complexity.
// 7. Works efficiently for large trees with up to 100,000 nodes.