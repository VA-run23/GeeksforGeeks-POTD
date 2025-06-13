/*
    1. We use binary search to find the minimum eating speed 's' that allows Koko to finish all bananas in 'k' hours.
    2. The search range is from '1' (minimum speed) to 'max_element(arr)' (maximum pile size).
    3. In each iteration, we check if Koko can finish all bananas within 'k' hours at speed 'mid = (left + right) / 2'.
    4. The 'canFinish' function calculates the total hours needed for a given speed using ceiling division '(bananas + speed - 1) / speed'.
    5. If Koko can finish within 'k' hours, we reduce the search space ('right = mid'); otherwise, we increase it ('left = mid + 1').
    6. The binary search ensures we find the smallest possible speed efficiently.
    7. Time Complexity: 'O(n log(max(arr)))' (binary search + checking feasibility), Space Complexity: 'O(1)' (constant extra space).
*/

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int left = 1, right = *max_element(arr.begin(), arr.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canFinish(vector<int>& arr, int k, int speed) {
        int hours = 0;
        for (int bananas : arr) {
            hours += (bananas + speed - 1) / speed; 
        }
        return hours <= k;
    }
};