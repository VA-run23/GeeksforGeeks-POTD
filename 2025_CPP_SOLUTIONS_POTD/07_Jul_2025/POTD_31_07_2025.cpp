/* 
    1. This function finds the largest integer included in at least 'k' intervals from the input list.
    2. It uses a sweep line strategy by adding +1 at the start and -1 at one past the end (i.e., end + 1) in a sorted map.
    3.  Key Insight: By doing events[end + 1] -= 1, we ensure the interval stays active through 'end' and expires immediately after, preserving the inclusive nature of the input intervals.
    4. The map keeps all critical points sorted so we can track active overlaps in linear order.
    5. While traversing, if active overlaps reach or exceed 'k', we record the current position (point - 1) as a candidate for "powerful integer".
    6. We continually update the result to reflect the maximum such integer found.
    7. Time Complexity: O(N log N) due to map inserts and traversal; Space Complexity: O(N) for storing event points.
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