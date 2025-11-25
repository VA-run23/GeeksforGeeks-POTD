/*
    1. The problem asks for XOR of XORs of all possible subarrays of arr[].
    2. Each element arr[i] is part of (i+1) * (n-i) subarrays, where n is the array size.
    3. If this count is odd, arr[i] contributes to the final XOR; if even, its effect cancels out.
    4. We loop through each index, compute count, and check its parity.
    5. For odd counts, we XOR ans with arr[i]; for even counts, we skip it.
    6. This avoids generating subarrays explicitly, reducing complexity from O(n^2) to O(n).
    7. Time Complexity: O(n);
       Space Complexity: O(1).
*/

class Solution{
public:
    int subarrayXor(vector<int> &arr)    {
        // code here
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++)        {
            long long cnt = (long long)(i + 1) * (n - i);
            if (cnt % 2 == 1){
                ans ^= arr[i];
            }
        }
        return ans;
    }
};