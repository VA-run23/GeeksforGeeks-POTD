/*
    1. This code defines a Trie-based solution to count the number of distinct substrings in a given string.
    2. Each Node contains 26 pointers (for lowercase 'a'–'z'), initialized to NULL, representing possible child links.
    3. For every starting index i in the string, we traverse forward (j = i to n-1) and insert substrings into the Trie.
    4. If a character path does not exist, a new Node is created, and the counter `cnt` is incremented (unique substring found).
    5. Shared prefixes are reused in the Trie, ensuring duplicates are not counted multiple times.
    6. Finally, the function returns `cnt`, which represents the total number of distinct substrings in the string.
    7. Time Complexity: O(n²) in worst case (inserting all substrings); Space Complexity: O(n²) due to Trie nodes.
*/

class Solution {
public:
    struct Node {
        Node* tr[26];
        Node() {
            for (int i = 0; i < 26; i++)
                tr[i] = NULL;
        }
        bool ContainsKey(char ch) { return (tr[ch - 'a'] != NULL); }
        void Put(char ch, Node* node) { tr[ch - 'a'] = node; }
        Node* Get(char ch) { return tr[ch - 'a']; }
    };

    int countSubs(string& s) {
        // code here
        Node* root = new Node();
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            Node* curr = root;
            for (int j = i; j < n; j++) {
                if (curr->ContainsKey(s[j]) == false) {
                    cnt++;
                    curr->Put(s[j], new Node());
                }
                curr = curr->Get(s[j]);
            }
        }
        return cnt;
    }
};