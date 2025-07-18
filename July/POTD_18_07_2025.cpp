/*
    1. The function computes the maximum possible LCM of any triplet of integers ≤ n.
    2. For n ≤ 3, it directly returns the known LCM values: 1, 2, and 6 respectively.
    3. For n > 3, it checks whether n is odd or even to choose the best triplet.
    4. If n is odd, the triplet {n, n-1, n-2} gives the highest LCM.
    5. If n is even and not divisible by 3, the triplet {n, n-1, n-3} avoids common factors.
    6. If n is divisible by both 2 and 3, the triplet {n-1, n-2, n-3} is chosen to maximize LCM.
    7. Time Complexity: O(1), Space Complexity: O(1) — all operations are constant-time arithmetic.
*/

class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if (n <= 2) return n;
        if (n == 3) return 6;

        int res;
        if (n % 2 != 0) {
            res = n * (n - 1) * (n - 2);
        } else {
            if (n % 3 != 0) {
                res = n * (n - 1) * (n - 3);
            } else {
                res = (n - 1) * (n - 2) * (n - 3);
            }
        }
        return res;
    }
};