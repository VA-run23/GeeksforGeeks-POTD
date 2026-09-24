// Maximum Height Disc Stack

/*
 *    1. The problem asks to stack discs such that:
 *       - Each disc has radius r[i] and height h[i].
 *       - A disc can be placed on another only if its radius is strictly larger.
 *    2. Goal: maximize total stack height.
 *    3. Approach:
 *       - Sort discs by radius.
 *       - Use coordinate compression on heights for efficient indexing.
 *       - Apply Fenwick Tree (BIT) to maintain maximum stack height ending at each height.
 *       - For each disc:
 *         - Query best stack height achievable with smaller/equal height.
 *         - Add current disc height to extend stack.
 *         - Update BIT with new value.
 *    4. Answer = maximum stack height found.
 *    5. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int,int>> discs(n);
        vector<int> vals;

        for (int i = 0; i < n; i++) {
            discs[i] = {r[i], h[i]};
            vals.push_back(h[i]);
        }

        sort(discs.begin(), discs.end()); 

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<int> bit(m + 1, 0);

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res = max(res, bit[idx]);
                idx -= idx & -idx;
            }
            return res;
        };

        auto update = [&](int idx, int val) {
            while (idx <= m) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };

        int ans = 0;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && discs[j].first == discs[i].first) j++;

            vector<pair<int,int>> pending;
            for (int k = i; k < j; k++) {
                int height = discs[k].second;
                int pos = lower_bound(vals.begin(), vals.end(), height) - vals.begin();
                int best = query(pos);
                int cur = best + height;
                pending.push_back({pos + 1, cur});
                ans = max(ans, cur);
            }

            for (auto &[pos, value] : pending) {
                update(pos, value);
            }

            i = j;
        }

        return ans;
    }
};

// Key Points
// 1. Sort discs by radius to enforce stacking order.
// 2. Coordinate compress heights for BIT indexing.
// 3. Query BIT for best stack ending below current height.
// 4. Extend stack by adding current disc height.
// 5. Update BIT with new stack height.
// 6. Answer = maximum stack height found.
// 7. Efficient O(n log n) solution using Fenwick Tree.