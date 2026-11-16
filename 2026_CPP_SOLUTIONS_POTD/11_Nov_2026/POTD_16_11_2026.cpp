// K-th Missing in Natural Numbers
/*
 * 1. Sort the array so numbers are processed in increasing order.
 *
 * 2. Assume k is the answer initially.
 *
 * 3. Traverse each element of the array:
 *    - If the current element is less than or equal to k,
 *      it occupies one natural number position before or at k.
 *    - Therefore, increment k to shift the target missing
 *      number one position ahead.
 *
 * 4. Continue until all relevant elements are processed.
 *
 * 5. The final value of k is the k-th missing natural number.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    int findKthSmall(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        for (int &i : arr) {
            if (i <= k)
                ++k;
        }

        return k;
    }
};

// Key Points
// 1. Sorts the array first.
// 2. Uses k as a moving target.
// 3. Every element <= k shifts the answer by one.
// 4. No explicit missing-number counting is needed.
// 5. Final k represents the k-th missing number.
// 6. Simple and efficient implementation.