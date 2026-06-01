// Maximum Product Subset of an Array

/*
 *    1. The problem requires finding the maximum product of a subset of the given array.
 *    2. Negative numbers can reduce product, but an even count of negatives increases it.
 *    3. Zero values must be handled carefully as they nullify product contributions.
 *    4. If all elements are zero, the maximum product is zero.
 *    5. If there is one negative and all others are zero, the maximum product is zero.
 *    6. If negatives are odd, exclude the smallest absolute negative to maximize product.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
    public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int size = arr.size();
        if (size == 1) {
            return arr[0];
        }
        
        const int mod = 1e9 + 7;
        int neg = 0;
        int zero = 0;
        int negMin = mod;
        long long ans = 1;
        
        for (int &val: arr) {
            if (val == 0) {
                zero++;
                continue;
            }
            if (val < 0) {
                neg++;
                negMin = min(negMin, abs(val));
            }
            
            ans = (1LL * val * ans) % mod;
        }
        
        if ((size == zero) || (size == 2 && neg == 1 && zero == 1)) {
            return 0;
        }
        
        if ((neg & 1) == 1) {
            ans = abs(ans / (1LL * negMin)) % mod;
        }
        
        return ans;
    }
};

// Key Points
// 1. Handle single-element arrays directly.
// 2. Track count of negatives and zeros.
// 3. Multiply all non-zero values into the product.
// 4. If all elements are zero, return zero.
// 5. If one negative and rest zeros, return zero.
// 6. If negatives are odd, exclude smallest absolute negative.
// 7. Use modulo to prevent overflow and maintain constraints.