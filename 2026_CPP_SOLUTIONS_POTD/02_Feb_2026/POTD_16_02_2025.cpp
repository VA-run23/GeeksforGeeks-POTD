/*
1. This function checks if a person can attend all meetings without overlaps.
2. It first sorts the intervals (meetings) based on their start times.
3. Sorting ensures meetings are in chronological order for easy comparison.
4. Then, it iterates through consecutive meetings to detect overlaps.
5. If the end time of one meeting exceeds the start time of the next, return false.
6. Otherwise, if no overlaps are found, return true.
7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) since sorting is in-place.
*/

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 0; i<n-1; i++){
            if(arr[i][1]> arr[i+1][0] )return false;
        }
        return true;
    }
};

// Key points:
// - Default sort works lexicographically (start time, then end time).
// - Custom comparator sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
//   (sorting by start time explicitly) makes intent clearer.
// - Both approaches are correct for this problem.
// - Custom comparator is good practice in interviews: it avoids ambiguity and shows clarity of thought.
// - Edge cases (empty or single meeting) are handled naturally.
// - The overlap check is simple and efficient.
// - This solution is optimal since sorting is necessary unless input is already sorted.
