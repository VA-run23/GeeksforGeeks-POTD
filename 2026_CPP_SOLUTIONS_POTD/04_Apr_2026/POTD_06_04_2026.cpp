// Huffman Encoding

/*
 *    1. Build a min-heap of nodes using character frequencies.
 *    2. Extract two smallest nodes and combine them into a parent node.
 *    3. Repeat until only one node remains, which becomes the root.
 *    4. Traverse the tree using preorder to assign binary codes.
 *    5. Left edge contributes '0' and right edge contributes '1'.
 *    6. Leaf nodes represent characters with their Huffman codes.
 *    7. Time Complexity: O(n log n), Space Complexity: O(n)
 */

class Solution {
  public:
  
    struct Node {
        int freq;
        char ch;
        Node* left;
        Node* right;
        int idx;
        
        Node(int f, char c, int i) {
            freq = f;
            ch = c;
            left = right = NULL;
            idx = i;
        }
    };
    
    struct cmp {
        bool operator()(Node* a, Node* b) {
            if (a->freq == b->freq)
                return a->idx > b->idx;
            return a->freq > b->freq;
        }
    };
    
    void preorder(Node* root, string str, vector<string> &res) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            res.push_back(str);
            return;
        }
        
        preorder(root->left, str + "0", res);
        preorder(root->right, str + "1", res);
    }
    
    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        for (int i = 0; i < s.size(); i++) {
            pq.push(new Node(f[i], s[i], i));
        }
        
        if (pq.size() == 1) {
            return {"0"};
        }
        
        while (pq.size() > 1) {
            Node* a = pq.top(); pq.pop();
            Node* b = pq.top(); pq.pop();
            
            Node* left;
            Node* right;
            
            if (a->freq < b->freq) {
                left = a;
                right = b;
            } else if (a->freq > b->freq) {
                left = b;
                right = a;
            } else {
                if (a->idx < b->idx) {
                    left = a;
                    right = b;
                } else {
                    left = b;
                    right = a;
                }
            }
            
            Node* parent = new Node(left->freq + right->freq, '#',
                                    min(left->idx, right->idx));
            
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        Node* root = pq.top();
        
        vector<string> res;
        preorder(root, "", res);
        
        return res;
    }
};

// Key Points
// 1. Huffman coding minimizes average code length.
// 2. Priority queue ensures smallest frequencies are combined first.
// 3. Preorder traversal generates binary codes for characters.
// 4. Stable ordering maintained using index for tie-breaking.
// 5. Single character case handled separately with code "0".
// 6. Efficient for variable-length encoding schemes.
// 7. Widely used in compression algorithms like JPEG and MP3.