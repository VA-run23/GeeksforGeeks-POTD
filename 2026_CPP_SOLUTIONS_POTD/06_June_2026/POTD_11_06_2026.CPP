// Equal Point in Brackets

/*
 *    1. The problem is to find the index where the number of opening brackets equals closing brackets.
 *    2. We traverse the string to count brackets.
 *    3. The equal point is where prefix count of '(' matches suffix count of ')'.
 *    4. This requires scanning the string and maintaining counts.
 *    5. The solution uses standard library functions for simplicity.
 *    6. The approach ensures correctness by leveraging count operations.
 *    7. Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
  public:
    int findIndex(string &s) {
        // code here
        return count(s.begin(), s.end(), ')');
    }
};

// Key Points
// 1. Problem focuses on balancing brackets.
// 2. Equal point is defined by matching counts of '(' and ')'.
// 3. Prefix and suffix counts are crucial.
// 4. Standard library functions simplify implementation.
// 5. Efficient solution with linear time complexity.
// 6. Constant space usage makes it optimal.
// 7. Useful for string and bracket-related problems.