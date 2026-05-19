// Minimum Multiplications to reach End

/*
 *    1. We are given an array of integers and two numbers: start and end.
 *    2. The task is to find the minimum steps to reach 'end' starting from 'start'.
 *    3. In each step, we can multiply the current number by any element of the array.
 *    4. After multiplication, we take the result modulo 1000 to keep values bounded.
 *    5. This problem can be solved using Breadth-First Search (BFS).
 *    6. BFS ensures the shortest path (minimum steps) is found efficiently.
 *    7. Time Complexity: O(1000 * n), Space Complexity: O(1000), where n = size of array.
 */

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        const int MOD = 1000;
        vector<int> dist(MOD, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end)
                return dist[end];

            for (int a : arr) {
                int x = (node * a) % MOD;

                if (dist[x] == -1) {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
            }
        }
        return -1;
    }
};

// Key Points
// 1. BFS is used to guarantee minimum steps.
// 2. Modulo 1000 ensures bounded state space.
// 3. Each state represents a number between 0–999.
// 4. Distance array tracks shortest path to each state.
// 5. Queue ensures level-order traversal of states.
// 6. If 'end' is unreachable, return -1.
// 7. Efficient for large arrays due to bounded search space.