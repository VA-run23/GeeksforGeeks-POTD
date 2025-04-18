/* 
    1. The Trie class implements a prefix tree data structure to store words efficiently. 
    2. It contains an internal structure TrieNode, which represents each node in the Trie. 
    3. Each TrieNode has an array of pointers (children[26]) to store child nodes, indexed by letters 'a' to 'z'. 
    4. The isEnd boolean flag indicates if a word ends at that node.
    5. The Trie constructor initializes the root node.
    6. The insert() function adds a word character by character, creating child nodes if they do not exist.
    7. When inserting, if a node for a character does not exist, it is allocated dynamically.
    8. The last node of the inserted word is marked with isEnd = true.
    9. The search() function checks if a given word exists in the Trie by following the path in the structure.
    10. If a node in the path does not exist, the word is not present, and the function returns false.
    11. Otherwise, if the last node in the word path has isEnd = true, it confirms the word exists.
    12. The isPrefix() function checks whether a given prefix exists by traversing the Trie.
    13. It follows the same traversal logic as search(), but does not check isEnd.
    14. Time Complexity: insert(), search(), and isPrefix() all run in **O(N)**, where N is the length of the word.
    15. Space Complexity: Worst-case space complexity is **O(M * 26)**, where M is the number of words stored.
*/


class Trie {
    private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

  public:

    Trie() {
        // implement Trie
        root = new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;

    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }


    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }
};
