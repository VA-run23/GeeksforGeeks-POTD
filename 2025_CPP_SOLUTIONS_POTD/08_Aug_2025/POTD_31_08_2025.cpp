/*
    1. This function solves the "Container With Most Water" problem using a two-pointer approach.
    2. It initializes two pointers at the start and end of the array and calculates the area between them.
    3. The area is determined by the shorter line and the distance between the pointers.
    4. To maximize area, the pointer at the shorter line is moved inward, hoping to find a taller line.
    5. This continues until the pointers meet, ensuring all potential maximum areas are considered.
    6. Time Complexity: O(n) — each element is visited at most once.
    7. Space Complexity: O(1) — no extra space is used beyond variables.
*/

/*
    The two-pointer approach employs a strategic trade-off: it progressively reduces the width between two lines while aiming to identify a taller line that offsets the loss in width, thereby maximizing the potential area.
*/

class Solution {
public:
    int maxWater(vector<int> &arr) {
        //code here
        if (arr.size() <= 1) return 0;

        int left = 0, right = arr.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            maxWater = max(maxWater, width * height);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};