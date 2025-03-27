 /*
    This function calculates the minimum number of platforms required at a railway station.
    The arrival and departure times of trains are sorted to handle events in chronological order.
    Two pointers i and j are used to traverse the arrival and departure arrays respectively.
    If a train arrives before the previous one departs, increment platforms; otherwise, decrement.
    maxPlatforms keeps track of the highest number of platforms required simultaneously.
    Sorting ensures that overlapping arrival/departure times are handled accurately.
    The algorithm efficiently manages overlapping intervals using two sorted arrays.
*/

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0, n = arr.size();

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }
};