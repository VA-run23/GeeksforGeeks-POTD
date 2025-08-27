/*
    1. The array is sorted to simplify checking the triangle inequality condition efficiently.
    2. We fix the largest side of the triangle as arr[i] and iterate from the end of the array.
    3. Using two pointers (left and right), we check if arr[left] + arr[right] > arr[i].
    4. If the condition is true, all elements between left and right form valid triangles with arr[i].
    5. We add (right - left) to the count and move the right pointer leftward.
    6. If the condition fails, we move the left pointer rightward to try a larger value.
    7. Time Complexity: O(n²); Space Complexity: O(1) — no extra space used beyond sorting.
*/

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), count = 0;

        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    count += (right - left);
                    right--; 
                } else {
                    left++;   
                }
            }
        }

        return count;
    }
};