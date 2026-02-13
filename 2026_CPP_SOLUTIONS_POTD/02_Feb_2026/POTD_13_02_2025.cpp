/*
    1. This class solves the problem of counting numbers ≥ some limit where (n - sum_of_digits(n)) ≥ d.
    2. The helper function `check(int n, int d)` computes the sum of digits of n and checks if n - sum ≥ d.
    3. The main function `getCount(int n, int d)` uses binary search to find the smallest number (limit) satisfying the condition.
    4. It searches between 1 and n, adjusting bounds based on whether `check(mid, d)` is true.
    5. Once the limit is found, the count of valid numbers is n - limit + 1; otherwise, returns 0.
    6. Time Complexity: O(log n * log n) because binary search runs O(log n) times and each digit sum check takes O(log n).
    7. Space Complexity: O(1) since only a few integer variables are used.
*/

class Solution {
  private:
    bool check(int n, int d) {
        int a = n, sum = 0;
        while (a > 0) {
            sum += a % 10;
            a = a / 10;
        }
        return (n - sum) >= d;
    }

  public:
    int getCount(int n, int d) {
        // code here
        int low = 1, high = n, limit = 0;
        ;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, d)) {
                limit = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        if (limit != 0)
            return n - limit + 1;
        return 0;
    }
};

// Key points:
// - The problem is about finding numbers where n - sum_of_digits(n) ≥ d.
// - A binary search is used to efficiently locate the smallest valid number.
// - Once found, the count is derived by subtracting the limit from n.
// - The helper function isolates digit sum logic for clarity.
// - Binary search ensures logarithmic efficiency compared to brute force.
// - Edge cases: if no number satisfies, return 0.
// - The approach balances correctness with efficiency using digit sum checks.
