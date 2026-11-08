// Minimum Time with 2 Scanners

/*
 *    1. The problem asks to find the minimum time required to scan n documents
 *       using two scanners that take s1 and s2 seconds per document.
 *
 *    2. Let mid be the number of documents assigned to Scanner 1.
 *       Then (n - mid) documents are assigned to Scanner 2.
 *
 *    3. Time taken by Scanner 1:
 *       - mid * s1
 *       Time taken by Scanner 2:
 *       - (n - mid) * s2
 *
 *    4. Since both scanners work simultaneously, total completion time is:
 *       max(mid * s1, (n - mid) * s2)
 *
 *    5. The objective is to find the distribution of documents that minimizes
 *       this maximum time.
 *
 *    6. The function is convex (unimodal), so binary search can be used to find
 *       the optimal split point efficiently.
 *
 *    7. Time Complexity: O(log n), Space Complexity: O(1).
 */

class Solution {
public:
    int minTime(int n, int s1, int s2) {
        int l = 0, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            long long cur =
                max(1LL * mid * s1,
                    1LL * (n - mid) * s2);

            long long nxt =
                max(1LL * (mid + 1) * s1,
                    1LL * (n - mid - 1) * s2);

            if (nxt < cur)
                l = mid + 1;
            else
                r = mid;
        }

        return (int)max(1LL * l * s1,
                        1LL * (n - l) * s2);
    }
};

// Key Points
// 1. Split n documents between two scanners.
// 2. Completion time is governed by the slower scanner.
// 3. Objective is to minimize max(time1, time2).
// 4. The answer depends on the optimal document distribution.
// 5. Binary search exploits the unimodal nature of the function.
// 6. Uses long long to avoid overflow.
// 7. Runs in O(log n) time with O(1) extra space.