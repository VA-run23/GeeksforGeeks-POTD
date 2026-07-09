// Count Pairs Divisible By K

/*
 *    1. Use modular arithmetic to classify elements by their remainder when divided by k.
 *    2. Maintain a frequency array of size k to count occurrences of each remainder.
 *    3. Pairs with remainder 0 can be formed among themselves using nC2 formula.
 *    4. For remainders r and k-r, pairs can be formed by multiplying their frequencies.
 *    5. Special case: when r == k-r (i.e., k is even), pairs are formed within that group using nC2.
 *    6. Iterate through remainders from 1 to k/2 to count all valid pairs.
 *    7. Time Complexity: O(n + k), Space Complexity: O(k).
 */

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<int> freq(k, 0);
        for (int num : arr) {
            freq[num % k]++;
        }
        
        int count = 0;
        count += (freq[0] * (freq[0] - 1)) / 2;
        
        for (int r = 1; r <= k/2; r++) {
            if (r == k - r) {
                count += (freq[r] * (freq[r] - 1)) / 2;
            } else {
                count += freq[r] * freq[k - r];
            }
        }
        
        return count;
    }
};

// Key Points
// 1. Frequency array captures distribution of remainders.
// 2. Remainder 0 elements pair among themselves.
// 3. Remainder r pairs with remainder k-r.
// 4. Handle special case when r == k-r (k even).
// 5. Use nC2 formula for intra-group pairing.
// 6. Efficiently counts pairs without nested loops.
// 7. Linear time and space solution relative to input size.