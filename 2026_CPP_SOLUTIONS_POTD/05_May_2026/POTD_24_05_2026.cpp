// Last Coin in a Game of Alternates

/*
 *    1. The problem involves finding the smallest coin value in an array.
 *    2. Each element in the array represents a coin denomination.
 *    3. The task is to iterate through the array to identify the minimum value.
 *    4. A variable is initialized with the first element to track the smallest coin.
 *    5. A loop compares each element with the current smallest value.
 *    6. The smallest value is updated whenever a smaller coin is found.
 *    7. Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int smallest = arr[0];
        int n = arr.size();
        
        for (int i = 0; i < n; i++)
            smallest = (arr[i] < smallest) ? arr[i] : smallest;
        
        return smallest;
    }
};

// Key Points
// 1. Initialize smallest with the first element.
// 2. Iterate through the array once.
// 3. Compare each element with the current smallest.
// 4. Update smallest when a smaller value is found.
// 5. Return the final smallest value.
// 6. Efficient solution with linear time complexity.
// 7. Constant space usage makes it optimal.