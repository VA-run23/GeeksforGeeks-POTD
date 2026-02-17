/*
    1. This function calculates the maximum number of overlapping intervals in a given list.
    2. It separates all start times and end times into two arrays and sorts them individually.
    3. For each interval, it counts how many intervals have started before or at its start time.
    4. It also counts how many intervals have ended before its start time.
    5. The difference between these counts gives the number of active overlapping intervals at that point.
    6. The maximum of these values across all intervals is stored as the answer.
    7. Time Complexity: O(n log n) due to sorting and binary search; Space Complexity: O(n) for storing starts and ends.
*/

class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        vector<int> starts, ends;
        
        for (auto &i : arr) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int ans = 0;
        
        for (auto &i : arr) {
            int s = upper_bound(starts.begin(), starts.end(), i[0]) - starts.begin();
            int e = lower_bound(ends.begin(), ends.end(), i[0]) - ends.begin();
            ans = max(ans, s - e);
        }
        
        return ans;
    }
};

// Key points:
// - The problem is about finding the maximum overlap among intervals.
// - Starts and ends are separated and sorted for efficient binary search.
// - For each interval, active overlaps are calculated using upper_bound and lower_bound.
// - The difference (s - e) gives the number of ongoing intervals at a given start.
// - The maximum across all intervals is the final answer.
// - Efficient use of sorting and binary search reduces complexity compared to brute force.
// - This approach balances clarity and performance for interval overlap problems.
