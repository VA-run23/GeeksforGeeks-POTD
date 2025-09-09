/*
    1. This function assigns each mouse to a hole such that the time taken by the last mouse to reach a hole is minimized.
    2. It first sorts both the 'mices' and 'holes' arrays to align mice with the nearest available holes.
    3. Sorting ensures that each mouse is paired with the closest hole in order, minimizing individual travel times.
    4. It then iterates through the arrays, calculating the absolute distance between each mouse and its assigned hole.
    5. The maximum of these distances is stored in 'maxTime', representing the worst-case time for any mouse.
    6. Finally, it returns 'maxTime' as the minimum time required for all mice to be safely in holes.
    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) as no extra space is used beyond input arrays.
*/

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int maxTime = 0;
        for (int i = 0; i < mices.size(); i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }

        return maxTime;
    }
};