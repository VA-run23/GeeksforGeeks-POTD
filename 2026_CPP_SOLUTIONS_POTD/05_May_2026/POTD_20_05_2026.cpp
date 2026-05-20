// Product Pair Problem

/*
 *    1. The task is to check if any pair in the array has a product equal to the target.
 *    2. Use a hash set to store previously seen numbers for quick lookup.
 *    3. Handle the special case when numbers or target involve zero.
 *    4. For each number, check if target is divisible by it.
 *    5. If divisible, compute the required complement and check in the set.
 *    6. Insert the current number into the set for future checks.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
    public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<long long> seen;
        for (long long num : arr) {
            if (num == 0) {
                if (target == 0 && !seen.empty()) {
                    return true;
                }
                seen.insert(num);
                continue;
            }
            
            if (target % num != 0) {
                seen.insert(num);
                continue;
            }
            
            long long needed = target / num;
            if (seen.count(needed)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

// Key Points
// 1. Uses hashing for O(1) average lookup.
// 2. Handles zero cases separately.
// 3. Avoids division by zero errors.
// 4. Works for both positive and negative numbers.
// 5. Efficient compared to brute force O(n^2).
// 6. Returns true immediately when a valid pair is found.
// 7. Overall optimal solution with linear time complexity.