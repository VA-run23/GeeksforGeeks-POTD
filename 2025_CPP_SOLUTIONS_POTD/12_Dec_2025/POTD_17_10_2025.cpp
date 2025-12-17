/*
    1. The function 'mergeOverlap' takes a 2D vector of intervals where each interval is represented as [start, end].
    2. First, the intervals are sorted by their starting point using a custom comparator to ensure proper merging order.
    3. A new vector 'merged' is created to store the final merged intervals.
    4. The code iterates through each interval in the sorted list.
    5. If 'merged' is empty or the current interval does not overlap with the last merged interval, it is directly added to 'merged'.
    6. If there is an overlap, the end of the last merged interval is updated to the maximum of both overlapping ends.
    7. Finally, the merged list of intervals is returned as the output.

    Time Complexity: O(n log n) → due to sorting the intervals, followed by a single O(n) traversal.  
    Space Complexity: O(n) → in the worst case, when no intervals overlap, all intervals are stored in 'merged'.
*/

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        for (auto& inter : arr) {
            if (merged.empty() || merged.back()[1] < inter[0]) {
                merged.push_back(inter);
            } else {
                merged.back()[1] = max(merged.back()[1], inter[1]);
            }
        }
        return merged;
    }
};
