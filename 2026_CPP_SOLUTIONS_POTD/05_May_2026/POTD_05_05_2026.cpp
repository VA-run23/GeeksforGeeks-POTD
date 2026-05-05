// Sum of XOR of all pairs

/*
 *    1. The problem requires calculating the sum of XOR values for all pairs in an array.
 *    2. XOR operation highlights differing bits between two numbers.
 *    3. Instead of brute force, we can count contributions of each bit position.
 *    4. For each bit, count how many numbers have it set and how many don’t.
 *    5. Each differing pair contributes to the sum at that bit position.
 *    6. Multiply contributions by the bit’s value (power of two).
 *    7. Time Complexity: O(n * logM), Space Complexity: O(1) where M is max element.
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
}

// Key Points
// 1. XOR highlights differing bits between two numbers.
// 2. Brute force approach is O(n^2), inefficient for large arrays.
// 3. Optimized approach counts contributions bit by bit.
// 4. Each bit contributes independently to the final sum.
// 5. Uses frequency of set/unset bits to avoid pairwise iteration.
// 6. Works in O(n * logM) where M is max element size.
// 7. Requires only constant extra space.