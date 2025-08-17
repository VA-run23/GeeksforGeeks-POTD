/*
    1. The function rearranges the array based on the absolute difference of each element from a given number x.
    2. It first calculates the absolute difference for each element and stores it along with its index in a vector of pairs.
    3. The vector of pairs is then sorted by the difference value using the default sort (which is not stable).
    4. A new vector 'ans' is created by retrieving elements from the original array using the sorted indices.
    5. The original array is updated with the rearranged values from 'ans'.
    6. This approach does not preserve the original order for elements with equal differences due to use of unstable sort.
    7. Time Complexity: O(n log n) for sorting; Space Complexity: O(n) for storing pairs and result array.
*/


class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> diff;

        for (int i = 0; i < n; i++) {
            int differ = abs(arr[i] - x);
            diff.push_back({differ, i});
        }

        sort(diff.begin(), diff.end());

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(arr[diff[i].second]);
        }

        arr = ans;
    }
};