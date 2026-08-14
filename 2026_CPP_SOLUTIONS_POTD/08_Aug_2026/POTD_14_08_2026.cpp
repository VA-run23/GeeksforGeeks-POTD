// Tricky Subset Problem

/*
 *    1. The problem asks whether a target x can be represented as a subset sum of a specially generated sequence.
 *    2. Start with initial value s, then iteratively generate new numbers by adding each element of arr to the running total.
 *    3. Stop generating when the next number exceeds x, since larger values are irrelevant for subset sums.
 *    4. Store all generated numbers in a vector nums.
 *    5. To check feasibility, greedily subtract the largest possible numbers from x (like subset sum using descending order).
 *    6. If target reduces to zero, return true; otherwise false.
 *    7. Time Complexity: O(n + m) where n is arr size and m is number of generated terms, Space Complexity: O(m).
 */

class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<long long> nums;
        long long tot = s;
        nums.push_back((long long)s);
        
        for (int a : arr) {
            long long next = tot + a;
            if (next > x) break;
            nums.push_back(next);
            tot += next;
        }
        
        long long target = x;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= target) {
                target -= nums[i];
            }
            if (target == 0) return true;
        }
        return false;
    }
};

// Key Points
// 1. Generates sequence starting from s using arr increments.
// 2. Stops when generated number exceeds target x.
// 3. Stores generated sequence in nums vector.
// 4. Greedy subtraction checks subset sum feasibility.
// 5. Works like subset sum but tailored to generated sequence.
// 6. Returns true if exact target achieved, else false.
// 7. Runs in O(n + m) time with O(m) space.