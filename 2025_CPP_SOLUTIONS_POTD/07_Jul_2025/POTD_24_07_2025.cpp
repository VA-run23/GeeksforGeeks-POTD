/*
1. The problem ignores ant collisions since direction swapping has no effect on who falls when.
2. Ants going left fall in 'pos' seconds — the one farthest from 0 takes the longest.
3. Ants going right fall in 'n - pos' seconds — the one closest to 0 takes the longest.
4. Iterate over 'left[]' to find max(pos), which is time to fall for the slowest left-bound ant.
5. Iterate over 'right[]' to find max(n - pos), which is time to fall for the slowest right-bound ant.
6. Return the maximum of these two — this is when the last ant falls off the plank.
7. Time Complexity: O(L + R); Space Complexity: O(1), where L and R are lengths of 'left' and 'right'.
*/

class Solution {
  public:`
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int lastTime = 0;
        for (int pos : left) lastTime = max(lastTime, pos);
        for (int pos : right) lastTime = max(lastTime, n - pos);
        return lastTime;
    }
};
