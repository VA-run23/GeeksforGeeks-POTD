// Smallest Number Not Possible as Subset Sum

/*
 *    1. Sort the array to process elements in increasing order.
 *    2. Initialize a variable `curr` to 1, representing the smallest number we cannot form yet.
 *    3. Traverse through the array elements one by one.
 *    4. If the current element is greater than `curr`, return `curr` as the answer.
 *    5. Otherwise, add the current element to `curr` to extend the range of possible sums.
 *    6. Continue until all elements are processed.
 *    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1).
 */

class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        long long curr=1;
        for(auto&val:arr){
            if(curr<val)return curr;
            curr+=val;
        }
        return curr;
    }
};

// Key Points
// 1. Sorting ensures we handle smaller elements first.
// 2. `curr` tracks the smallest unformable sum.
// 3. If an element is larger than `curr`, we cannot form `curr`.
// 4. Adding elements extends the range of achievable sums.
// 5. Greedy approach guarantees correctness.
// 6. Efficient solution with minimal extra space.
// 7. Works well for both small and large arrays.