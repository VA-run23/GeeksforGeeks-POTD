// Find Two Pairs with Same Sum

/*
 *    1. The problem asks to find four indices (a, b, c, d) such that:
 *       - arr[a] + arr[b] = arr[c] + arr[d]
 *       - All indices are distinct.
 *
 *    2. Generate all possible pairs (i, j) where i < j and compute their sum.
 *
 *    3. Use a hash map to store:
 *       - Key   = pair sum.
 *       - Value = first pair of indices producing that sum.
 *
 *    4. If the current sum has not been seen before,
 *       store the pair in the hash map.
 *
 *    5. If the sum already exists:
 *       - Retrieve the previous pair (a, b).
 *       - Check that all four indices are distinct.
 *
 *    6. Form the candidate answer {a, b, i, j}.
 *       - Keep the lexicographically smallest valid quadruple.
 *
 *    7. Time Complexity: O(n²), Space Complexity: O(n²).
 */

class Solution {
public:
    vector<int> findPairs(vector<int> &arr) {
        int n = arr.size();

        unordered_map<long long, pair<int, int>> mp;

        vector<int> ans = {-1, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long sum = (long long)arr[i] + arr[j];

                if (mp.count(sum)) {

                    auto [a, b] = mp[sum];

                    if (a != i && a != j &&
                        b != i && b != j) {

                        vector<int> temp = {a, b, i, j};

                        if (ans[0] == -1 || temp < ans) {
                            ans = temp;
                        }
                    }
                }
                else {
                    mp[sum] = {i, j};
                }
            }
        }

        return ans;
    }
};

// Key Points
// 1. Uses a hash map to store the first occurrence of each pair sum.
// 2. Generates all possible pairs in O(n²).
// 3. Equal sums indicate a potential answer.
// 4. Ensures all four indices are distinct.
// 5. Lexicographically smallest quadruple is maintained.
// 6. Stores only the first pair for each sum.
// 7. Runs in O(n²) time with O(n²) extra space.