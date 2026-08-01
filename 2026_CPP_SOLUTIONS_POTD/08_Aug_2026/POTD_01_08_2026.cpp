// Max After m Range Increments

/*
 *    1. The problem asks to find the maximum value in an array after applying m range increment operations.
 *    2. Each operation increases values between indices l and r by a given increment k.
 *    3. Instead of updating each element directly, use a difference array technique for efficiency.
 *    4. Add k at index l and subtract k at index r+1 to mark the effect of the range increment.
 *    5. Compute prefix sums over the difference array to reconstruct final values.
 *    6. Track the maximum value during prefix sum computation to get the answer.
 *    7. Time Complexity: O(n + m), Space Complexity: O(n).
 */

class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<long long int> sum(n+1, 0LL);
        int aSize = a.size();
        for(int i=0; i<aSize; i++){
            int l = a[i];    
            int r = b[i];    
            long long int inc = k[i];
            
            sum[l] += inc;
            sum[r+1] -= inc;
        }
        
        long long int maxi = sum[0];
        for(int i=1; i<=n; i++){
            sum[i] += sum[i-1];
            maxi = max(maxi, sum[i]);
        }
        
        return maxi;
    }
};

// Key Points
// 1. Uses difference array technique for efficiency.
// 2. Avoids direct element updates for each operation.
// 3. Adds increment at l and subtracts at r+1.
// 4. Prefix sums reconstruct final array values.
// 5. Tracks maximum during prefix sum computation.
// 6. Handles large increments with long long type.
// 7. Runs in O(n + m) time with O(n) space.