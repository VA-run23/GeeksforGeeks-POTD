/*
1. The function 'minCandy' takes a vector of ratings 'arr' and aims to distribute candies such that each child gets at least one candy.
2. A vector 'candies' of size 'n' is initialized with all values as 1, ensuring the minimum requirement.
3. First pass (left to right): if a child has a higher rating than the previous one, they get one more candy than the previous child.
4. Second pass (right to left): if a child has a higher rating than the next one, update their candy count to be at least one more than the next child.
5. This ensures both left and right neighbor conditions are satisfied for all children.
6. Finally, sum up all values in 'candies' to get the total minimum candies required.
7. Time Complexity: O(n) due to two linear passes; Space Complexity: O(n) for the 'candies' vector.
*/

// Key Points:
// - Ensures fairness: higher rating → more candies than neighbors.
// - Two-pass strategy handles both increasing and decreasing rating sequences.
// - Efficient solution with linear time and space complexity.

class Solution {
public:
    int minCandy(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        return total;
    }
};