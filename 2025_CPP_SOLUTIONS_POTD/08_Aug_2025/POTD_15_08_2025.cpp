/*
    1. This function inserts a new interval into a sorted list of non-overlapping intervals and merges any overlaps.
    2. First, it adds all intervals that end before the new interval starts—no overlap here.
    3. Then, it merges all intervals that overlap with the new interval by updating its start and end.
    4. After merging, it adds the combined interval to the result.
    5. Finally, it appends all remaining intervals that start after the new interval ends.
    6. This ensures the final list remains sorted and non-overlapping.
    7. Time Complexity: O(n), Space Complexity: O(n) — where n is the number of intervals.
*/

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);


        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};