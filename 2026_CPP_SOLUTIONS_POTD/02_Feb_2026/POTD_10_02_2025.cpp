/*
    1. This code solves the "Koko Eating Bananas" problem using binary search on eating speed.
    2. The helper function `canFinish` calculates total hours needed at a given speed.
    3. It uses ceiling division `(bananas + speed - 1) / speed` to compute hours per pile.
    4. The main function `kokoEat` searches for the minimum speed that allows finishing within k hours.
    5. Search space is between 1 and the maximum pile size, narrowing via binary search.
    6. Time Complexity: O(n log m), where n = number of piles, m = max pile size.
    7. Space Complexity: O(1), since only constant extra space is used.
*/

class Solution {
  private:
    bool canFinish(vector<int>& arr, int k, int speed) {
        int hours = 0;
        for (int bananas : arr) {
            hours += (bananas + speed - 1) / speed; 
        }
        return hours <= k;
    }
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
};

// Key points:
// - The problem is about finding the minimum eating speed to finish bananas within k hours.
// - Binary search is applied on the possible speed range [1, max pile].
// - The helper function checks feasibility at a given speed.
// - Ceiling division ensures correct calculation of hours per pile.
// - The loop narrows down until the smallest valid speed is found.
// - Efficient due to O(n log m) complexity, suitable for large inputs