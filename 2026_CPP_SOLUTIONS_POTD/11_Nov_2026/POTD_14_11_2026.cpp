// Maximum Equal Sum of Three Stacks

/*
 *    1. The problem asks to make the sums of three stacks equal by removing
 *       elements only from the top of the stacks.
 *
 *    2. Compute the total sum of all three stacks:
 *       - sum1 = sum of stack1
 *       - sum2 = sum of stack2
 *       - sum3 = sum of stack3
 *
 *    3. Maintain three pointers i, j, and k representing the current top
 *       element of each stack.
 *
 *    4. If all three sums become equal, that sum is the maximum possible
 *       equal sum and is returned.
 *
 *    5. Otherwise, remove the top element from the stack having the
 *       largest current sum.
 *
 *    6. Update the corresponding sum and pointer after removal.
 *       If any stack becomes empty before equality is achieved,
 *       return 0.
 *
 *    7. Time Complexity: O(n1 + n2 + n3), Space Complexity: O(1).
 */

class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here

        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        int sum3 = accumulate(s3.begin(), s3.end(), 0);

        int i = 0, j = 0, k = 0;

        while (true) {

            if (sum1 == sum2 && sum2 == sum3)
                return sum1;

            if (sum1 >= sum2 && sum1 >= sum3) {

                if (i == s1.size())
                    return 0;

                sum1 -= s1[i++];
            }
            else if (sum2 >= sum1 && sum2 >= sum3) {

                if (j == s2.size())
                    return 0;

                sum2 -= s2[j++];
            }
            else {

                if (k == s3.size())
                    return 0;

                sum3 -= s3[k++];
            }
        }

        return 0;
    }
};

// Key Points
// 1. Computes initial sums of all three stacks.
// 2. Uses pointers to simulate removing top elements.
// 3. Always removes from the stack with the largest sum.
// 4. Gradually reduces sums toward equality.
// 5. Returns the common sum once all three sums match.
// 6. Returns 0 if any stack becomes empty first.
// 7. Runs in O(n1 + n2 + n3) time with O(1) extra space.