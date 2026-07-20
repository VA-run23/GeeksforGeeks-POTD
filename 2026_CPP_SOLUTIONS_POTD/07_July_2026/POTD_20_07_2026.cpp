// Shortest Unique Prefix for Each Word

/*
 *    1. The problem asks to find the shortest unique prefix for every word in a given list.
 *    2. Build a Trie where each node tracks how many words pass through it (`count`).
 *    3. Insert all words into the Trie, incrementing counts along each path.
 *    4. For each word, traverse the Trie character by character.
 *    5. Stop as soon as you reach a node with `count == 1` — that prefix is unique.
 *    6. Collect these prefixes for all words in the list.
 *    7. Time Complexity: O(Σ|word|), Space Complexity: O(Σ|word|).
 */

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        int count;
        TrieNode() {
            count = 0;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    vector<string> findPrefixes(vector<string>& arr) {
        // Build Trie
        TrieNode* root = new TrieNode();
        
        for (const string& s : arr) {
            TrieNode* curr = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!curr->children[idx])
                    curr->children[idx] = new TrieNode();
                curr = curr->children[idx];
                curr->count++;
            }
        }
        
        // Find shortest unique prefix for each word
        vector<string> result;
        for (const string& s : arr) {
            TrieNode* curr = root;
            string prefix = "";
            for (char c : s) {
                int idx = c - 'a';
                curr = curr->children[idx];
                prefix += c;
                if (curr->count == 1)
                    break;
            }
            result.push_back(prefix);
        }
        return result;
    }
};

// Key Points
// 1. Trie efficiently stores words and tracks prefix counts.
// 2. Each node’s `count` tells how many words share that prefix.
// 3. Stop at the first node with `count == 1` for uniqueness.
// 4. Guarantees shortest unique prefix for every word.
// 5. Handles overlapping prefixes naturally.
// 6. Linear time in total characters across all words.
// 7. Clean and efficient solution using Trie data structure.