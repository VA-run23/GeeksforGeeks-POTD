// Count Frequency of an Element in a Given Range

/*
 *    1. We are given an array and multiple queries.
 *    2. Each query asks for the frequency of a specific element in a subarray range [L, R].
 *    3. To solve efficiently, we preprocess the array by storing indices of each element.
 *    4. This is done using an unordered_map where each key maps to a vector of positions.
 *    5. For each query, we retrieve the vector of indices for the target element.
 *    6. Then we count how many indices fall within the given range [L, R].
 *    7. Time Complexity: O(N + Q*K), Space Complexity: O(N), where K is average frequency of queried element.
 */

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        int m = queries.size();
        vector<int> ans(m, 0);

        for (int i = 0; i < m; i++) {
            vector<int> a = mp[queries[i][2]];
            int l = queries[i][0], r = queries[i][1];
            int cnt = 0;
            for (int j = 0; j < (int)a.size(); j++) {
                if (a[j] >= l && a[j] <= r)
                    cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

// Key Points
// 1. Preprocessing stores indices of each element for quick access.
// 2. Queries are answered by checking indices within [L, R].
// 3. Uses unordered_map for O(1) average lookup.
// 4. Straightforward counting loop per query.
// 5. Works well if queries are limited and element frequency is small.
// 6. Can be optimized further using binary search on sorted indices.
// 7. Binary search reduces query time to O(logK) instead of O(K).