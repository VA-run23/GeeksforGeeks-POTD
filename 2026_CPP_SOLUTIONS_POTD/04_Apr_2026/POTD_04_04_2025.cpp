// Gray Code Generation (Recursive Prefix Method)

/*
 *    1. Gray code is a sequence where consecutive values differ by only one bit.
 *    2. The base case starts with 1-bit codes: ["0", "1"].
 *    3. At each step, existing codes are prefixed with "0" in place.
 *    4. Simultaneously, reversed codes are prefixed with "1" and appended.
 *    5. This creates left and right halves that expand outward from the center.
 *    6. Backward iteration ensures adjacency between successive codes is preserved.
 *    7. Time Complexity: O(2^n * n), Space Complexity: O(2^n * n).
 */

class Solution {
  public:
    void gen(vector<string>& vec, int n) {
        // code here
        if(n == 1) return;
        int h = vec.size();
        for(int i = h-1; i >= 0; i--) {
            vec.push_back('1' + vec[i]);
            vec[i] = '0' + vec[i];
        }
        gen(vec, n-1);
    }

    vector<string> graycode(int n) {
        // code here
        vector<string> res = {"0", "1"};
        gen(res, n);
        return res;
    }
};

// Key Points
// 1. Starts with base case ["0", "1"].
// 2. Each recursion level doubles the sequence size.
// 3. Prefix "0" modifies existing codes in place.
// 4. Prefix "1" appends reversed codes to the end.
// 5. Sequence expands outward from the center.
// 6. Backward iteration preserves one-bit difference.
// 7. Produces standard Gray code sequence with exponential complexity.