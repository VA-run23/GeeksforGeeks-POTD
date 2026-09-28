// Range GCD Queries using Segment Tree

/*
 * Problem:
 *   - You’re given an array.
 *   - Queries are of two types:
 *     1. Find GCD of elements in range [l, r].
 *     2. Update arr[idx] = val.
 *
 * Approach:
 *   - Build a segment tree where each node stores the GCD of its segment.
 *   - Query: recursively combine results from left and right children.
 *   - Update: modify leaf and propagate changes upward.
 *
 * Complexity:
 *   - Build: O(n)
 *   - Query: O(log n)
 *   - Update: O(log n)
 */

class Solution {
  public:
    vector<int> tree;
    int n;

    // GCD helper
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Build segment tree
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Point update
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Range query
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // outside range
        if (l <= start && end <= r) return tree[node]; // fully inside
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return gcd(left, right);
    }

    // Process queries
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 0) { // query type
                ans.push_back(query(1, 0, n - 1, q[1], q[2]));
            } else { // update type
                update(1, 0, n - 1, q[1], q[2]);
            }
        }
        return ans;
    }
};