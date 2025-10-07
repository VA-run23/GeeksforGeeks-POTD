/*
    1. This function computes the bottom view of a binary tree using level order traversal and horizontal distance mapping.
    2. A queue stores pairs of nodes and their horizontal distances (HD) from the root, starting with HD = 0.
    3. A map 'mp' keeps track of the latest node encountered at each HD, overwriting previous nodes to ensure bottom-most visibility.
    4. As we traverse the tree level by level, we enqueue left children with HD - 1 and right children with HD + 1.
    5. The map ensures that for each HD, only the last (bottom-most) node encountered remains.
    6. After traversal, we extract the values from the map in order of increasing HD to form the bottom view.
    7. Time Complexity: O(N), Space Complexity: O(N), where N is the number of nodes in the tree.
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* cur=q.front().first;
            int col=q.front().second;
            q.pop();
            mp[col]=cur->data;
            if(cur->left){
                q.push({cur->left, col-1});
            }
            if(cur->right){
                q.push({cur->right, col+1});
            }
        }
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};