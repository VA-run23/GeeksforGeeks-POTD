/*
    1. This code solves the problem of finding the minimum number of days required to make 'm' bouquets from an array of flower bloom days.
    2. Each bouquet must consist of 'k' adjacent flowers that have bloomed on or before a given day.
    3. The helper function 'canMakeBouquets' checks if it's possible to make 'm' bouquets by counting valid groups of 'k' adjacent bloomed flowers.
    4. The main function 'minDaysBloom' uses binary search between the minimum and maximum bloom days to find the earliest day that satisfies the bouquet condition.
    5. If the total number of flowers is less than k × m, it's impossible to make the bouquets, so it returns -1.
    6. Binary search narrows down the minimum day by checking feasibility at each midpoint using the helper function.
    7. Time Complexity: O(n × log(max_day)), where n is the number of flowers; Space Complexity: O(1), as no extra space is used beyond variables.
*/

class Solution {
public:
    bool canMakeBouquets(vector<int>& arr, int day, int k, int m) {
        int count = 0, flowers = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    count++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return count >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        if (n < k * m) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(arr, mid, k, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};