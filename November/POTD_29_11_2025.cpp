/*
   1. The function countSetBits(n) calculates the total number of set bits (1s) 
      in binary representations of all numbers from 1 to n inclusive.
   2. We iterate over each bit position i (starting from 0) until (1 << i) <= n, 
      meaning we only consider bit positions that can appear in numbers up to n.
   3. For each bit position i, the pattern of set bits repeats in cycles of length 
      2^(i+1). Example: for i=0 (LSB), pattern is 0101..., for i=1, pattern is 0011..., etc.
   4. We compute the number of complete cycles: (n+1)/clen, where clen = 2^(i+1). 
      Each full cycle contributes exactly 2^i set bits at position i.
   5. We add cycles * (1 << i) to res, which accounts for all set bits contributed 
      by complete cycles at bit position i.
   6. Then we handle the remainder part: (n+1) % clen. If remainder > 2^i, 
      it means extra numbers beyond full cycles also have the bit set, so we add 
      (remainder - 2^i) to res.
   7. Finally, res accumulates contributions from all bit positions, giving the 
      total count of set bits from 1 to n.
*/

// Time Complexity: O(log n)  → because we iterate over bit positions up to log2(n).
// Space Complexity: O(1)    → only a few integer variables are used.

class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int res = 0;
        for (int i = 0; (1 << i) <= n; i++) {
            int clen = 1 << (i + 1);   
            int cycles = (n + 1) / clen;
            res += cycles * (1 << i);
    
            int rem = (n + 1) % clen;
            if (rem > (1 << i)) {
                res += rem - (1 << i);
            }
        }
        return res;
    }
};