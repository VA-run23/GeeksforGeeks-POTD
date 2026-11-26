// Range Vowel Count Queries

/*
 *    1. The problem asks to find the number of vowels present in multiple substring ranges.
 *
 *    2. Use a prefix sum array where:
 *       - pref[i] stores the number of vowels in s[0...i-1].
 *
 *    3. Traverse the string once and build the prefix array.
 *       - Increment count when the current character is a vowel.
 *
 *    4. For each query [l, r]:
 *       - Number of vowels = pref[r + 1] - pref[l].
 *
 *    5. Prefix sums allow answering each query in O(1) time.
 *
 *    6. Store the answer for every query in a result vector.
 *
 *    7. Time Complexity: O(n + q), Space Complexity: O(n).
 */

class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here

        int n = s.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] +
                (s[i] == 'a' || s[i] == 'e' ||
                 s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u');
        }

        vector<int> ans;

        for (auto &q : queries) {
            ans.push_back(pref[q[1] + 1] - pref[q[0]]);
        }

        return ans;
    }
};

// Key Points
// 1. Uses prefix sums for efficient range queries.
// 2. pref[i] stores vowel count up to index i-1.
// 3. Vowels considered: a, e, i, o, u.
// 4. Each query is answered in O(1).
// 5. Range answer = pref[r+1] - pref[l].
// 6. Avoids scanning substrings repeatedly.
// 7. Runs in O(n + q) time with O(n) extra space.