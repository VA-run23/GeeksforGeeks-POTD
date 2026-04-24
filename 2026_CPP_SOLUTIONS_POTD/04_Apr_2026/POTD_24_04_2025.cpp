// Buildings Receiving Sunlight

/*
 *    1. We are given an array representing building heights.
 *    2. A building is visible if it is taller than or equal to all buildings before it.
 *    3. We traverse the array from left to right.
 *    4. Keep track of the maximum height encountered so far.
 *    5. If the current building height is greater than or equal to this maximum, it is visible.
 *    6. Increment the count of visible buildings and update the maximum height.
 *    7. Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int lm = arr[0];
        int ans = 1, n = arr.size();
        for(int i = 1; i<n; i++){
            if(arr[i]>=lm){
                lm = arr[i];
                ans++;
            }
        }
        return ans;
    }
}

// Key Points
// 1. Traverse the array only once.
// 2. Maintain the maximum height seen so far.
// 3. Compare each building height with the maximum.
// 4. Count buildings that are taller or equal to the maximum.
// 5. Update the maximum when a taller building is found.
// 6. Works efficiently in linear time.
// 7. Uses constant extra space.