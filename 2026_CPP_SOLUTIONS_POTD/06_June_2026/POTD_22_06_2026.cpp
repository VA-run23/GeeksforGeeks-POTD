// Container With Most Water

/*
 *    1. We are given an array representing heights of vertical lines.
 *    2. The goal is to find two lines that together with the x-axis form a container.
 *    3. The container should hold the maximum possible water.
 *    4. Use two pointers: one at the start and one at the end.
 *    5. Calculate area as min(height[i], height[j]) * (j - i).
 *    6. Move the pointer with the smaller height inward to maximize area.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
    public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size();
        int i = 0, j = n - 1;
        int maxi = 0;
        
        while (i<j) {
            maxi = max(maxi, min(height[i], height[j])*(j - i));
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        
        return maxi;
    }
};

// Key Points
// 1. Two-pointer approach is optimal.
// 2. Start with widest container and shrink inward.
// 3. Area depends on minimum of two heights.
// 4. Moving taller line doesn’t help, so move shorter one.
// 5. Brute force O(n^2) is possible but inefficient.
// 6. Optimal solution runs in linear time.
// 7. Requires only constant extra space.