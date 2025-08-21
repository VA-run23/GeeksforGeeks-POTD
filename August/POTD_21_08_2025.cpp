/*
    1. The array is first sorted to allow efficient selection of elements with controlled spacing.
    2. Binary search is applied on the possible minimum difference range from 0 to max(arr) - min(arr).
    3. For each mid value, we greedily try to select k elements such that each is at least mid apart.
    4. We start with the first element and count how many elements satisfy the spacing condition.
    5. If we can select k elements, we try for a larger minimum difference; otherwise, we reduce it.
    6. The final answer is the largest minimum difference for which k elements can be selected.
    7. Time Complexity: O(n log(maxDiff)), Space Complexity: O(1) — efficient for large inputs.
*/


class Solution {
public:
    int maxMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int left = 0, right = arr[n-1] - arr[0];
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int count = 1;
            int lastSelected = arr[0];
            
            for (int i = 1; i < n; i++) {
                if (arr[i] - lastSelected >= mid) {
                    count++;
                    lastSelected = arr[i];
                    if (count == k) break;
                }
            }
            
            if (count >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};