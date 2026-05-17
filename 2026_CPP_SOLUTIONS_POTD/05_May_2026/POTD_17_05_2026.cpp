 // Make the Array Beautiful

/*
 *    1. The problem requires transforming an array into a "beautiful" form.
 *    2. A beautiful array is defined by removing adjacent opposite-signed integers.
 *    3. Positive followed by negative or negative followed by positive cancels out.
 *    4. We use a stack-like approach to maintain the final sequence.
 *    5. Traverse the array and push/pop elements based on sign conditions.
 *    6. This ensures only valid consecutive elements remain in the result.
 *    7. Time Complexity: O(n), Space Complexity: O(n) due to stack usage.
 */

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> answer;
         for(int i : arr) {
             if(answer.size()==0)
                     answer.push_back(i);
             else if((answer[answer.size()-1] >= 0 && i < 0) || (answer[answer.size()-1] < 0 && i >= 0)) {
                 answer.pop_back();
             } else {
                 answer.push_back(i);
             }
         }

         return answer;
    }
};

// Key Points
// 1. Uses stack-like behavior with vector.
// 2. Cancels out adjacent opposite-signed integers.
// 3. Maintains order of valid elements.
// 4. Efficient single-pass traversal.
// 5. Handles edge cases like empty array.
// 6. Works for both positive and negative numbers.
// 7. Achieves O(n) time and space complexity.