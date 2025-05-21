/*
    1. We initialize left as 1 and right as m * n, which represent the smallest and largest numbers in the multiplication table.
    2. The function func(x) counts how many numbers in the table are ≤ x, using min(n, x / i) for each row.
    3. We use binary search on the range [left, right] to efficiently find the k-th smallest number.
    4. In each iteration, we calculate the mid-point and check how many numbers are ≤ mid using func(mid).
    5. If func(mid) >= k, it means mid is a valid candidate, so we store ans and move right leftward.
    6. Otherwise, we increase left, narrowing our search space toward larger numbers.
    7. Once the loop ends, ans holds the k-th smallest number from the multiplication table.
*/



class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int left = 1, right = m * n, ans = -1;

        auto func = [&](int x) {
            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(n, x / i);
            }
            return count;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (func(mid) >= k) {a
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
