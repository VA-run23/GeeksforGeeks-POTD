// Maximum Subset XOR

/*
 *    1. The problem asks to find the maximum XOR value obtainable from any subset of the given array.
 *    2. XOR behaves like addition without carry in binary, so maximizing XOR means setting as many higher bits as possible.
 *    3. Approach: repeatedly pick the largest element (highest bit set) and try to include it in the XOR result.
 *    4. Reduce other elements using this number, similar to Gaussian elimination in binary, to build an independent basis.
 *    5. Continue until all numbers are reduced to 0, ensuring we’ve extracted all independent contributions to XOR.
 *    6. The result is the maximum subset XOR value achievable from the array.
 *    7. Time Complexity: O(n · log(max element)), Space Complexity: O(1).
 */

class Solution {
    public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int N = arr.size();
        if (N == 0)
            return 0;
        
        int x = 0;
        
        while (true) {
            int y = *max_element(arr.begin(), arr.end());
            
            if (y == 0)
                return x;
            
            x = max(x, x ^ y);
            
            for (int i = 0; i < N; i++) {
                arr[i] = min(arr[i], arr[i] ^ y);
            }
        }
        
        return x;
    }
};

// Key Points
// 1. Builds a basis of independent XOR contributors.
// 2. Greedily maximizes XOR by combining them.
// 3. Works like Gaussian elimination in binary.
// 4. Efficient O(n log(max element)) solution.
// 5. Final result is the maximum subset XOR.
// 6. Stops when all elements are reduced to 0.
// 7. Uses bitwise properties to ensure optimality.