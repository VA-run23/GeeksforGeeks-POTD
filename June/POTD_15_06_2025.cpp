
/* 
    1. The function finds the smallest divisor that ensures the sum of ceil(arr[i] / divisor) is ≤ k.
    2. We initialize binary search on possible divisors in the range [1, max(arr)].
    3. The mid-point divisor is calculated, and we compute the sum using sumByDivisor().
    4. If the sum is ≤ k, we update the result and search for smaller divisors (right = mid - 1).
    5. If the sum exceeds k, we need a larger divisor, so we adjust search space (left = mid + 1).
    6. The binary search ensures an optimal solution in O(N log M) time complexity.
    7. The space complexity is O(1) since no extra memory beyond input storage is used.
*/
class Solution {
  public:
      int sumByDivisor(vector<int>& arr, int divisor) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / divisor); 
        }
        return sum;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int left = 1, right = *max_element(arr.begin(), arr.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sumByDivisor(arr, mid) <= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};