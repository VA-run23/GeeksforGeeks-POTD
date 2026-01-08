/*
    1. The function iterates over the array using two pointers (start and end) to maintain a sliding window.  
    2. Each time an odd number is encountered, it increments oddCount and stores its index in a deque.  
    3. If oddCount exceeds k, the window is shrunk from the left until exactly k odd numbers remain.  
    4. When oddCount equals k, the number of valid subarrays ending at 'end' is calculated as (firstOdd - start + 1).  
    5. This works because shifting 'start' up to the first odd index still preserves exactly k odds in the window.  
    6. The deque ensures efficient tracking of the earliest odd index in the current window.  
    7. Time Complexity: O(n) since each element is processed at most twice; Space Complexity: O(k) for storing odd indices.  
*/

// Key Points:
// - Sliding window technique is used to avoid brute force checking of all subarrays.
// - Deque helps track positions of odd numbers efficiently.
// - The formula (firstOdd - start + 1) counts all valid subarrays ending at 'end' with exactly k odds.
// - Efficient solution compared to O(n^2) brute force, suitable for large input sizes.

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;

        int start = 0;             
        int oddCount = 0;           
        deque<int> oddIndices;      

        for (int end = 0; end < n; end++) {
            if (arr[end] % 2 == 1) {
                oddCount++;
                oddIndices.push_back(end);
            }

            while (oddCount > k) {
                if (arr[start] % 2 == 1) {
                    oddCount--;
                    oddIndices.pop_front();
                }
                start++;
            }

            if (oddCount == k) {
                int firstOdd = oddIndices.front();

                ans += (firstOdd - start + 1);
            }
        }
        return ans;
    }
};