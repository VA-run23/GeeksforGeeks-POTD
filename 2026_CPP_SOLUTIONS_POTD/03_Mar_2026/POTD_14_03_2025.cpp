// Top View of Binary Tree

/*
 *    1. Perform a level-order traversal using a queue.
 *    2. Track horizontal distance (HD) of each node from root.
 *    3. Store the first node encountered at each HD in a map.
 *    4. Maintain minimum and maximum HD values during traversal.
 *    5. After traversal, iterate from min HD to max HD.
 *    6. Collect nodes corresponding to each HD into the result vector.
 *    7. Time Complexity: O(N), Space Complexity: O(N) where N = number of nodes.
 */

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;

        unordered_map<int, int> mp; 
        
        queue<pair<Node*, int>> q; 
        
        q.push({root, 0});
        int minlvl = 0;
        int maxlvl = 0;
        
        while(!q.empty()) {
            Node *temp = q.front().first;
            int lvl = q.front().second;
            q.pop(); 

            if(mp.find(lvl) == mp.end()) {
                mp[lvl] = temp->data;
            }
            
            minlvl = min(minlvl, lvl);
            maxlvl = max(maxlvl, lvl);
            
            if(temp->left)  
                q.push({temp->left, lvl - 1});
            
            if(temp->right) 
                q.push({temp->right, lvl + 1}); 
        }
        
        for(int i = minlvl; i <= maxlvl; i++) {
            if(mp.count(i)) { 
                ans.push_back(mp[i]); 
            }
        }
        
        return ans;
    }
};

// Key Points
// 1. Use BFS traversal to ensure level-order processing.
// 2. Horizontal distance (HD) helps identify top view nodes.
// 3. Only the first node at each HD is stored.
// 4. Map ensures uniqueness of HD entries.
// 5. Track min and max HD to build ordered result.
// 6. Result is constructed left-to-right using HD range.
// 7. Efficient solution with O(N) time and space complexity.