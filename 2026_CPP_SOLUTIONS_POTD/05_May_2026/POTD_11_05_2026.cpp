 // Palindrome Pairs

/*
 *    1. Build two tries: one for normal words, one for reversed words
 *    2. Insert each word into both tries with its index
 *    3. Traverse tries to check for possible palindrome concatenations
 *    4. Use reverse checks to validate suffix/prefix matches
 *    5. Ensure self-pair cases are excluded
 *    6. Return true if any valid palindrome pair is found
 *    7. Time Complexity: O(N * L^2), Space Complexity: O(N * L) where N = number of words, L = max length of word
 */

class trie {
public:
    vector<int> ind;
    vector<trie*> vec;
    trie() { vec.resize(26, NULL); }
};

class Solution {
public:
    void process1(trie* t, vector<string>& st) {
        int ct = -1;
        for (auto i : st) {
            ct++;
            trie* head = t;
            for (auto j : i) {
                int h = j - 'a';
                if (head->vec[h] == NULL)
                    head->vec[h] = new trie;
                head = head->vec[h];
            }
            head->ind.push_back(ct);
        }
        return;
    }

    void process2(trie* t, vector<string>& st) {
        int ct = -1;
        for (auto i : st) {
            ct++;
            reverse(i.begin(), i.end());
            trie* head = t;
            for (auto j : i) {
                int h = j - 'a';
                if (head->vec[h] == NULL)
                    head->vec[h] = new trie;
                head = head->vec[h];
            }
            head->ind.push_back(ct);
        }
        return;
    }

    bool palindromePair(vector<string>& arr) {
        // code here
        trie *t1 = new trie, *t2 = new trie;
        process1(t1, arr);
        process2(t2, arr);
        int ct = -1;
        for (auto i : arr) {
            ct++;
            trie* head = t2;
            string s = i;
            reverse(s.begin(), s.end());
            for (auto j : i) {
                int h = j - 'a';
                if (head->vec[h] == NULL) {
                    break;
                } else
                    head = head->vec[h];
                s.pop_back();
                if (head->ind.size()) {
                    if (head->ind.size() == 1 && head->ind[0] == ct)
                        break;
                    int a = 0, b = s.size() - 1;
                    while (a <= b) {
                        if (s[a] != s[b])
                            break;
                        a++;
                        b--;
                    }
                    if (a > b)
                        return true;
                }
            }
        }
        ct = -1;

        for (auto i : arr) {
            ct++;
            trie* head = t1;
            string s = i;
            reverse(i.begin(), i.end());
            for (auto j : i) {
                int h = j - 'a';
                if (head->vec[h] == NULL) {
                    break;
                } else
                    head = head->vec[h];
                s.pop_back();
                if (head->ind.size()) {
                    if (head->ind.size() == 1 && head->ind[0] == ct)
                        break;
                    int a = 0, b = s.size() - 1;
                    while (a <= b) {
                        if (s[a] != s[b])
                            break;
                        a++;
                        b--;
                    }
                    if (a > b)
                        return true;
                }
            }
        }
        return false;
    }
};

// Key Points
// 1. Two tries are used: forward and reverse
// 2. Each word is inserted with its index
// 3. Traversal checks for palindrome suffix/prefix matches
// 4. Reverse checks ensure correctness
// 5. Self-pair cases are excluded
// 6. Returns true if any valid palindrome pair exists
// 7. Complexity is quadratic in word length due to palindrome checks