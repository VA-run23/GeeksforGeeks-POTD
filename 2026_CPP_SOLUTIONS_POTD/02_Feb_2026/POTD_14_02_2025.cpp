/*
    1. This code solves the Painter’s Partition Problem using binary search on the answer.
    2. The `check` function verifies if the array can be divided into at most k partitions with max sum ≤ mid.
    3. It greedily accumulates elements until exceeding mid, then starts a new partition.
    4. The `minTime` function sets search bounds: low = max element, high = sum of all elements.
    5. Binary search narrows down the minimum feasible maximum partition sum.
    6. Time Complexity: O(n log(sum of array)), since each check is O(n) and binary search runs log(sum).
    7. Space Complexity: O(1), as only a few variables are used beyond the input array.
*/

class Solution {
public:
    bool check(vector<int>& a, int n, int k, int mid) {
        int sum = 0;
        int cnt = 1;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] <= mid) {
                sum = sum + a[i];
            } else {
                cnt++;
                sum = a[i];
            }
        }

        if (cnt <= k)
            return true;
        else
            return false;
    }

    int minTime(vector<int>& a, int k) {
        // code here
        int n = a.size();

        int low = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > low)
                low = a[i];
        }

        int high = 0;
        for (int i = 0; i < n; i++) {
            high = high + a[i];
        }

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(a, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

// Key points:
// - Problem: Partition array into k subarrays minimizing the maximum sum.
// - Approach: Binary search on possible maximum sums.
// - Greedy check ensures feasibility for each mid value.
// - Lower bound = largest element, upper bound = total sum.
// - Optimal answer found when check passes and search narrows.
// - Efficient compared to brute force partitioning.
// - Widely used in load balancing and scheduling problems.
