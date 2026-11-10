// Hash Map Frequency Counting
/*
 *    1. The problem asks for the first element whose frequency
 *       becomes exactly k while traversing the array from left to right.
 *
 *    2. Use an unordered_map to store the frequency of each element.
 *
 *    3. Traverse the array one element at a time.
 *
 *    4. For every element:
 *       - Increment its frequency.
 *       - If the updated frequency becomes k,
 *         immediately return that element.
 *
 *    5. Since the array is processed from left to right,
 *       the first element reaching frequency k is the answer.
 *
 *    6. If no element reaches frequency k,
 *       return -1.
 *
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */
class Solution {
public:
    int firstElementKTime(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (auto it : arr)
            if (++mp[it] == k)
                return it;

        return -1;
    }
};

// Key Points
// 1. Uses a hash map to maintain element frequencies.
// 2. Traverses the array only once.
// 3. Frequency is updated using ++mp[it].
// 4. Returns immediately when a frequency becomes k.
// 5. Ensures the first valid element is returned.
// 6. Returns -1 if no element occurs k times.
// 7. Runs in O(n) time with O(n) extra space.