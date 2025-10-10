/*
    1. This function performs a zigzag level order traversal of a binary tree using a queue for BFS and a deque for level-wise ordering.
    2. A boolean flag 'right' toggles at each level to determine the direction of traversal: left-to-right or right-to-left.
    3. For each level, nodes are processed and their values are stored in a deque ('dq') to allow efficient front/back access.
    4. Child nodes of the current level are enqueued for the next level traversal.
    5. Depending on the 'right' flag, values from 'dq' are pushed into the result vector 'ans' either from the front or back.
    6. This ensures zigzag ordering: odd levels go left-to-right, even levels go right-to-left.
    7. Time Complexity: O(N), Space Complexity: O(N), where N is the number of nodes in the tree.
*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        bool right = false;
        q.push(root);
        
        while(!q.empty()){
            right = !right;
            int n = q.size();
            deque<int> dq;
            
            while(n--){
              auto z = q.front();
              q.pop();
              
              dq.push_back(z->data);
              
              if(z->left)
                q.push(z->left);
              if(z->right)
                q.push(z->right);
                
            }
            
            if(right){
                while(dq.size()>0){
                    ans.push_back(dq.front());
                    dq.pop_front();
                }
            }else{
                while(dq.size()>0){
                    ans.push_back(dq.back());
                    dq.pop_back();
                }
            }
        }
        return ans;
    }
};