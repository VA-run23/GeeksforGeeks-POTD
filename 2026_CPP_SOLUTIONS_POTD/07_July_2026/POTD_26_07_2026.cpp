// Print Binary Tree Levels in Sorted Order

/*
 *    1. The problem asks to print each level of a complete binary tree
 *       (given as array input) in sorted order.
 *    2. Treat the array as a binary tree:
 *       - Left child index = 2*i + 1
 *       - Right child index = 2*i + 2
 *    3. Use BFS traversal with a queue to process nodes level by level.
 *    4. For each level:
 *       - Collect all node values in a temporary vector.
 *       - Sort the vector.
 *       - Push it into the answer.
 *    5. Continue until all nodes are processed.
 *    6. Time Complexity: O(n log n) (due to sorting at each level),
 *       Space Complexity: O(n).
 */

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        queue<int> q;
        q.push(0);  // start from root index
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            
            while (size--) {
                int i = q.front();
                q.pop();
                
                temp.push_back(arr[i]);
                
                // push left child
                if (2*i + 1 < n) {
                    q.push(2*i + 1);
                }
                // push right child
                if (2*i + 2 < n) {
                    q.push(2*i + 2);
                }
            }
            
            // sort values at this level
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        
        return ans;
    }
};

// Key Points
// 1. Array representation of complete binary tree.
// 2. BFS traversal ensures level-wise processing.
// 3. Sort each level before storing.
// 4. Queue manages indices of nodes.
// 5. Efficient O(n log n) solution.