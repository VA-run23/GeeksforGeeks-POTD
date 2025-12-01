/*
    1. This code defines a Trie-based solution to count pairs (i, j) such that (arr[i] XOR arr[j]) < k.
    2. The Trie structure stores binary representations of numbers, with each node tracking how many numbers pass through it.
    3. The insert() function adds a number into the Trie bit by bit (from MSB to LSB), incrementing counts along the path.
    4. The query() function checks how many previously inserted numbers satisfy (x XOR y) < k by traversing the Trie with bitwise logic.
    5. If the current bit of k is 1, counts from the branch where XOR = 0 are added, then traversal continues on the XOR = 1 branch.
    6. If the current bit of k is 0, traversal is restricted to the XOR = 0 branch only, ensuring the XOR stays below k.
    7. Time Complexity: O(n * logM), where n = array size and logM = number of bits (≈16); Space Complexity: O(n * logM) for Trie nodes.
*/

class Solution {
public:
    struct Trie{
        Trie* child[2];
        int cnt;
        Trie(){
            child[0]=child[1]=nullptr;
            cnt=0;
        }
    };

    Trie* root=new Trie();

    void insert(int x){
        Trie* node=root;
        for (int i=15;i>=0;i--){
            int bit=(x>>i)&1;
            
            if(!node->child[bit]){
                node->child[bit]=new Trie();
            }
                
            node = node->child[bit];
            node->cnt++;
        }
    }

    int query(int x,int k) {
        Trie* node=root;
        int res = 0;
        for (int i = 15;i>=0;i--){
            if(!node){
                break;
            }
            
            int xb=(x>>i) & 1;
            int kb=(k>>i) & 1;

            
            if (kb==1){
                int want = xb; 
                if (node->child[want]){
                    res+=node->child[want]->cnt;
                }
                    
                node=node->child[xb ^ 1];
            } 
            else { 
                int want = xb;
                node=node->child[want];
            }
        }
        return res;
    }

    int cntPairs(vector<int>& arr, int k) {
        // code here
        int ans=0;
        for (int x : arr) {
            ans+=query(x, k); 
            insert(x);
        }
        
        return ans;
    }
};