/*
   1. The function `donutsByChef(t, r)` calculates how many donuts a chef with rank `r` can make in time `t`
      using the quadratic formula derived from r*(k*(k+1))/2 ≤ t.
   2. The helper `canMake(ranks, n, t)` checks if all chefs together can make at least `n` donuts within time `t`
      by summing donuts produced by each chef.
   3. In `minTime(ranks, n)`, we apply binary search on the minimum possible time to fulfill all orders.
      The search space ranges from 0 to rmin * n * (n+1)/2 (upper bound using fastest chef).
   4. At each step, we compute `mid` and check feasibility using `canMake`; if possible, reduce `hi` else increase `lo`.
   5. The binary search ensures we minimize the maximum time needed while still producing at least `n` donuts.
   6. Time Complexity: O(N log(maxTime)), where N = number of chefs and maxTime ≈ rmin * n^2.
      Each binary search iteration checks all chefs.
   7. Space Complexity: O(1), as only constant extra variables are used besides input.
*/

/* Key Points:
   - Uses binary search to minimize time.
   - Quadratic formula helps compute donuts per chef efficiently.
   - `canMake` ensures feasibility check at each mid.
   - Efficient compared to brute force, suitable for large n.
*/

class Solution {
  public:
    int donutsByChef(int t, int r) {
        double D = 1.0 + 8.0 * t / r;
        return int((-1.0 + sqrt(D)) / 2.0);
    }
    bool canMake(vector<int>& ranks, int n, int t) {
        int total = 0;
        for (int r : ranks) {
            total += donutsByChef(t, r);
            if (total >= n)
                return true;
        }
        return false;
    }
    int minTime(vector<int>& ranks, int n) {
        int rmin = *min_element(ranks.begin(), ranks.end());
        int hi = rmin * n * (n + 1) / 2;
        int lo = 0, ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(ranks, n, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};