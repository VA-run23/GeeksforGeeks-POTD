/*
    1. This function applies a quadratic transformation: f(x) = A*x^2 + B*x + C.
    2. The input array is already sorted, allowing us to use a two-pointer approach.
    3. If A >= 0, the transformed values are largest at the ends, so we fill the result from back to front.
    4. If A < 0, the transformed values are smallest at the ends, so we fill the result from front to back.
    5. We iterate once through the array (O(n)), comparing left and right transformed values to insert them in order.
    6. Auxiliary space is O(n) because we store results in a new array before returning.
    7. Time Complexity: O(n), Space Complexity: O(n), avoiding O(n log n) sorting after transformation.
*/


class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int idx = (A >= 0) ? n - 1 : 0;

        auto quad = [&](int x) { return A * x * x + B * x + C; };

        while (left <= right) {
            int leftVal = quad(arr[left]);
            int rightVal = quad(arr[right]);

            if (A >= 0) { 
                if (leftVal > rightVal) {
                    ans[idx--] = leftVal;
                    left++;
                } else {
                    ans[idx--] = rightVal;
                    right--;
                }
            } else {
                if (leftVal < rightVal) {
                    ans[idx++] = leftVal;
                    left++;
                } else {
                    ans[idx++] = rightVal;
                    right--;
                }
            }
        }
        return ans;
    }
};