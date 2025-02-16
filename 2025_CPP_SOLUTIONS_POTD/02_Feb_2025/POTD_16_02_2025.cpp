class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == nullptr){
                res.push_back(-1); // Use -1 to represent null
            } else {
                res.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return res;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        if(arr.empty() || arr[0] == -1) return nullptr;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i < arr.size()){
            Node* curr = q.front();
            q.pop();

            if(arr[i] != -1){
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
            if(i < arr.size() && arr[i] != -1){
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};