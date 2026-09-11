// Values with Equal Array Remainders

/*
 *    1. The problem asks to find how many values of k exist such that all elements in arr give the same remainder when divided by k.
 *    2. If all elements are equal, then any k works → return -1.
 *    3. Otherwise, compute gcd of differences between elements.
 *    4. The valid k values are exactly the divisors of this gcd.
 *    5. Count divisors of gcd efficiently by iterating up to sqrt(g).
 *    6. Each divisor pair contributes 1 or 2 depending on equality.
 *    7. Time Complexity: O(n + √g), Space Complexity: O(1).
 */

class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) return -1;

        int g = 0;
        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        int count = 0;
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;
                if (i * i != g) {
                    count++;
                }
            }
        }

        return count;
    }
};

// Key Points
// 1. If all elements equal → return -1.
// 2. Compute gcd of differences between elements.
// 3. Valid k values are divisors of gcd.
// 4. Count divisors by iterating up to sqrt(g).
// 5. Each divisor pair contributes to count.
// 6. Efficient O(n + √g) solution.
// 7. Uses O(1) extra space.