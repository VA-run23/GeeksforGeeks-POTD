/*
    1. Convert the input vector to an unordered_set for O(1) lookups of allowed digits.
    2. If n == 1, return the count of allowed digits (excluding 0 if present), since single-digit numbers can't start with 0.
    3. total = number of all valid n-digit numbers (first digit must be non-zero, so 9 × 10^(n-1)).
    4. exclude = count of n-digit numbers that don’t contain any allowed digits, using (10 - sz)^n.
    5. If 0 is not an allowed digit, subtract numbers starting with non-zero disallowed digits: (10 - sz)^(n - 1).
    6. Final result is the total minus the excluded ones — i.e. numbers that contain at least one allowed digit.
    7. Time: O(n); Space: O(sz) for set storage; pow operations are constant time for small n (≤9 as per constraints).
*/

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        unordered_set<int> allowed(arr.begin(), arr.end());
        int sz = allowed.size();
        if (n == 1)
            return allowed.count(0) ? sz - 1 : sz;

        int total = 9 * pow(10, n - 1);        
        int exclude = pow(10 - sz, n);        
        if (!allowed.count(0))
            exclude -= pow(10 - sz, n - 1); 
        return total - exclude;
    }
};