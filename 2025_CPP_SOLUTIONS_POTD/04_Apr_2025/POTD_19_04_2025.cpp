/* 
1. This code uses a Trie data structure to efficiently compute the maximum XOR 
   between two numbers in an array. 
2. The insert(int num)  function stores each number in the Trie as a binary representation, 
   inserting bits from most significant to least significant.
3. The  findmx(int num)  function searches for the maximum XOR by prioritizing the opposite 
   bit at every level to maximize the XOR value.
4. The  Solution  class inserts all elements from the array into the Trie for efficient lookup 
   and then computes the highest possible XOR.
5. Instead of brute-force O(N²) comparisons, the Trie-based approach reduces the complexity 
   to O(N), making it significantly faster.
6. Each number is traversed bit by bit (32-bit integers), making insertion and search operations 
   efficient and quick.
   
7.  Time Complexity:  O(N) (each number is inserted and searched bit by bit).  
    Space Complexity:  O(N) (Trie stores binary representations, requiring additional nodes). 
*/


class TrieNode {
    public:
        TrieNode *left; 
        TrieNode *right;
    };
    
    class Trie {
    public:
        TrieNode *root;
    
        Trie() {
            root = new TrieNode();
        }
    
        void insert(int num) {
            TrieNode *cur = root;
            for (int i = 31; i >= 0; i--) { 
                int bit = (num >> i) & 1;
                if (bit == 0) {
                    if (!cur->left) cur->left = new TrieNode();
                    cur = cur->left;
                } else {
                    if (!cur->right) cur->right = new TrieNode();
                    cur = cur->right;
                }
            }
        }
    
        int findmx(int num) {
            TrieNode *cur = root;
            int mx = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (bit == 0) {
                    if (cur->right) { 
                        mx |= (1 << i);
                        cur = cur->right;
                    } else {
                        cur = cur->left;
                    }
                } else {
                    if (cur->left) {
                        mx |= (1 << i);
                        cur = cur->left;
                    } else {
                        cur = cur->right;
                    }
                }
            }
            return mx;
        }
    };
    
    class Solution {
    public:
        int mx(vector<int>& arr) {
            // code here
            Trie trie;
            for (int num : arr) {
                trie.insert(num);
            }
    
            int mx = 0;
            for (int num : arr) {
                mx = max(mx, trie.findmx(num));
            }
            return mx;
        }
    };