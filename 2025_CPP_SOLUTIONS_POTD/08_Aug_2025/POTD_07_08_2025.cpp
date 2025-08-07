/*
    1. The function takes a vector of time strings in "HH:MM:SS" format and converts each to total seconds since midnight.
    2. It stores these converted times in a vector called 'times'.
    3. The vector is sorted to arrange the times in chronological order.
    4. It then calculates the minimum difference between consecutive times in the sorted list.
    5. To handle the wrap-around at midnight, it also computes the difference between the last and first time.
    6. The smallest of all these differences is returned as the result.
    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(n) for storing converted times.
*/

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size();
        vector<int> times;


        for (int i = 0; i < n; i++) {
            int h = stoi(arr[i].substr(0, 2));
            int m = stoi(arr[i].substr(3, 2));
            int s = stoi(arr[i].substr(6, 2));
            int seconds = h * 3600 + m * 60 + s;
            times.push_back(seconds);
        }


        sort(times.begin(), times.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }

        int wrapDiff = 86400 - times[n - 1] + times[0]; 
        minDiff = min(minDiff, wrapDiff);

        return minDiff;
    }
};