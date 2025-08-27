/*
    1. The array is first sorted to ensure that triangle inequality can be checked efficiently.
    2. We iterate through all triplets (i, j, k) such that i < j < k.
    3. For each triplet, we check if arr[i] + arr[j] > arr[k], which is the triangle condition.
    4. If the condition is true, we count the triangle by incrementing 'ans'.
    5. If the condition fails, we break early since further values of k will only be larger.
    6. This approach avoids checking all combinations and leverages sorting for early termination.
    7. Time Complexity: O(n³) in worst case; Space Complexity: O(1) as no extra space is used.
*/

// Initially, I tried without breaking the innermost loop, which caused a TLE. Since the array is already sorted, I realized that if the current combination doesn't form a triangle, then the subsequent ones won't either.

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int ans = 0;
        int n = arr.size();
        for(int i =0; i<n-2; i++){
            for(int j =i+1; j<n-1; j++){
                for(int k = j+1; k<n; k++){
                    if((arr[i]+arr[j]) > arr[k] ){
                        ans++;
                    }else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
