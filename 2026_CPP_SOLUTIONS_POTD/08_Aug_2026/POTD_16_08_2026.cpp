// Minimum Product Subset

/*
 *    1. The problem asks to find the minimum product of a non-empty subset of the array.
 *    2. Track the count of negative numbers, smallest positive number, and smallest absolute negative number.
 *    3. Multiply all non-zero elements to get the overall product.
 *    4. If there are no negatives:
 *       - If zero exists, answer is 0 (choose subset {0}).
 *       - Otherwise, answer is the smallest positive number.
 *    5. If negatives are even, remove the smallest absolute negative to maximize negativity and minimize product.
 *    6. If negatives are odd, product itself is the minimum.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int negativeCount = 0;
        int smallPos = INT_MAX;
        int smallAbsNeg = INT_MAX;
        long long product = 1;
        bool hasZero = false;

        for (int x : arr) {
            if (x == 0) {
                hasZero = true;
                continue;
            }
            product *= x;
            if (x < 0) {
                negativeCount++;
                smallAbsNeg = min(smallAbsNeg, -x);
            } else {
                smallPos = min(smallPos, x);
            }
        }

        if (negativeCount == 0) {
            if (hasZero) return 0;
            return smallPos;
        }

        if (negativeCount % 2 == 0) {
            product /= -smallAbsNeg;
        }

        return (int)product;
    }
};

// Key Points
// 1. Handles zeros separately to allow subset {0}.
// 2. Tracks smallest positive and smallest absolute negative.
// 3. Product of all non-zero elements is baseline.
// 4. If no negatives, answer is smallest positive or 0 if zero exists.
// 5. If negatives are even, remove smallest absolute negative.
// 6. If negatives are odd, product itself is minimum.
// 7. Runs in O(n) time with O(1) space.