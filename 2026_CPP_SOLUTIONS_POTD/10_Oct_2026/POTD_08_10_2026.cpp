// Maximum Frequency with K Increments

/*
 * 1. Problem:
 *    - Given an array and integer k.
 *    - You can increment elements at most k times in total.
 *    - Find maximum frequency of any element after increments.
 *
 * 2. Sort array:
 *    - Sorting helps group equal elements and makes prefix sums useful.
 *
 * 3. Build prefix sum:
 *    - pref[i] = sum of arr[0..i].
 *    - Used to quickly compute sum of subarray.
 *
 * 4. Iterate over each unique element arr[i]:
 *    - Skip duplicates to avoid redundant work.
 *
 * 5. Find range of equal elements:
 *    - Use lower_bound to find index of first element > arr[i].
 *    - Range [mid..index-1] are candidates to be incremented up to arr[i].
 *
 * 6. Binary search for left boundary:
 *    - Check if total increments needed ≤ k.
 *    - total = (count * arr[i]) - sum_of_subarray.
 *    - If valid, update maximum frequency.
 *
 * 7. Final answer:
 *    - Return maximum frequency found across all elements.
 */

class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<long long> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = arr[i] + pref[i - 1];
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && arr[i] == arr[i - 1]) continue;

            int index = lower_bound(arr.begin(), arr.end(), arr[i] + 1) - arr.begin();
            int l = 0, r = index - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long sum = pref[index - 1] - ((mid - 1) >= 0 ? pref[mid - 1] : 0);
                long long size = (index - mid) * 1LL * arr[i];
                long long total = size - sum;

                if (total <= k) {
                    maxi = max(maxi, index - mid);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return maxi;
    }
};

// 🔑 Key Points
// - Sort + prefix sum enables efficient range calculations.
// - Binary search finds minimal left boundary for valid increments.
// - total increments = (count * target) - sum_of_subarray.
// - Skip duplicates to avoid redundant checks.
// - Answer = maximum frequency achievable with ≤ k increments.
// - Time complexity: O(n log n).
// - Space complexity: O(n).