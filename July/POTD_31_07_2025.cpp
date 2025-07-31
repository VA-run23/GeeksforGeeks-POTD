/* 
    1. This function identifies the largest integer that lies in at least 'k' intervals from the input list.
    2. It uses a sweep line technique by recording +1 at the start and -1 just after the end of each interval in a map.
    3. The map 'events' automatically keeps interval points sorted, helping us track changes in interval overlap efficiently.
    4. As we iterate through the map, 'activeInterval' maintains the count of current overlapping intervals.
    5. Whenever the count is ≥ k, we update 'powerful' to the greatest value satisfying the condition.
    6. This ensures that the returned value is the maximum point present in at least 'k' intervals.
    7. Time Complexity: O(N log N) for map operations; Space Complexity: O(N) for storing event markers.
*/

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int, int> events;


        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            events[start] += 1;     
            events[end + 1] -= 1;
        }

        int activeInterval= 0;
        int powerful = -1;
        int prevPoint = -1;

        for (auto& [point, delta] : events) {
            if (activeInterval>= k && prevPoint != -1) {
                powerful = max(powerful, point - 1); 
            }

            activeInterval+= delta;
            prevPoint = point;
        }

        return powerful;
    }
    
};