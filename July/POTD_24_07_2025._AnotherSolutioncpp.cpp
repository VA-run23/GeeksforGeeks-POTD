/*
    1. Each ant's position is paired with its direction: -1 for left, +1 for right.
    2. All ants are collected into a vector and fed into a min-heap to sort by position.
    3. The heap ensures ants are processed in left-to-right order, though this is not strictly necessary.
    4. For each ant, we calculate time to fall: it's either 'pos' (going left) or 'n - pos' (going right).
    5. 'lastTime' tracks the maximum such fall time across all ants.
    6. Final result is the latest time any ant would fall off the plank.
    7. Time Complexity: O(m log m); Space Complexity: O(m), where m = left.size() + right.size().
*/

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        vector<pair<int,int>> all;
        for (int x : left) all.push_back(make_pair(x, -1));
        for (int x : right) all.push_back(make_pair(x, 1));


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(all.begin(), all.end());

        int lastTime = 0;
        while (!pq.empty()) {
            pair<int, int> top = pq.top(); pq.pop();
            int pos = top.first;
            int dir = top.second;

            int timeToFall = (dir == -1) ? pos : (n - pos);
            lastTime = max(lastTime, timeToFall);
        }

        return lastTime;
    }
};