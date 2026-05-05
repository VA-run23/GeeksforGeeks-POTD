// Sum of XOR of all pairs

/*
 *    1. The problem requires calculating the sum of XOR values for all pairs in an array.
 *    2. XOR of two numbers highlights differing bits between them.
 *    3. Instead of brute force, we analyze each bit position independently.
 *    4. For each bit, count how many numbers have it set and how many don’t.
 *    5. Each differing pair contributes to the sum at that bit position.
 *    6. Multiply contributions by the bit’s value (1 << bit).
 *    7. Time Complexity: O(32 * n) ≈ O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long ans = 0;

        for(int bit = 0; bit < 32; bit++) {
            long long bitPresent = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] & (1 << bit)) bitPresent++;
            }
            long long countUnset = n - bitPresent;
            ans += bitPresent * countUnset * (1LL << bit);
        }
        return ans;
    }
};

// Key Points
// 1. Brute force O(n^2) approach is too slow for large arrays.
// 2. Bitwise contribution method reduces complexity to O(n).
// 3. Each bit is processed independently, avoiding pairwise iteration.
// 4. Works efficiently for up to 32-bit integers.
// 5. Uses long long to handle large sums safely.
// 6. Space usage is constant, no extra data structures needed.
// 7. Elegant solution leveraging properties of XOR and bit manipulation.