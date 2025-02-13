// class Solution {
//   public:
//     bool findTarget(Node *root, int target) {
//         // your code here.
//         if(root == NULL) return false;
//         Node* ptr = root;
//         multiset<int> ms;
//         while(ptr != NULL){
//             ms.insert(ptr->data);
//             if(ms.find(target- root->data) != ms.end()){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
  public:
    bool findTarget(Node* root, int target) {
        unordered_set<int> uset;
        return find(root, target, uset);
    }

  private:
    bool find(Node* node, int target, unordered_set<int>& uset) {
        if (node == NULL) return false;

        if (uset.find(target - node->data) != uset.end()) {
            return true;
        }

        uset.insert(node->data);
        return find(node->left, target, uset) || find(node->right, target, uset);
    }
};