/*
    1. This code uses an optimized Boyer-Moore Voting Algorithm variant to find elements appearing more than ⌊n/3⌋ times in an array.
    2. It maintains two candidate variables and their respective counts during a single pass through the array.
    3. When counts hit zero, they are replaced with the current number as potential majority candidates.
    4. This ensures we only keep track of up to two possible majority elements (at most two can exceed n/3 frequency).
    5. A second pass verifies how many times each candidate actually occurs.
    6. If their actual count exceeds n/3, they're added to the result vector.
    7. Time Complexity: O(n); Space Complexity: O(1) — as only a few variables are used irrespective of input size.
*/

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int count1 = 0, count2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;

        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) { candidate1 = num; count1 = 1; }
            else if (count2 == 0) { candidate2 = num; count2 = 1; }
            else { count1--; count2--; }
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        sort(result.begin(), result.end()); 
        return result;
    }
};
