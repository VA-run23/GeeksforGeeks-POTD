/*
    1. Initialize a max-heap (priority_queue) to always access the largest element quickly.
    2. Calculate the total sum of the array and set the target as half of that sum.
    3. While the current sum is greater than the target, repeatedly halve the largest element.
    4. Subtract the largest element from the sum, halve it, add it back, and push the halved value into the heap.
    5. Count each halving operation as one step toward reducing the sum.
    6. Using double ensures high floating-point precision, avoiding rounding errors from float.
    7. Time Complexity: O(n + k log n), where k is the number of operations; Space Complexity: O(n) for the heap.
*/

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double total = 0;
        for (int num : arr) {
            pq.push(num);
            total += num;
        }

        double target = total / 2.0;
        int ops = 0;

        while (total > target) {
            double top = pq.top(); pq.pop();
            total -= top;
            top /= 2.0;
            total += top;
            pq.push(top);
            ops++;
        }

        return ops;
    }
};