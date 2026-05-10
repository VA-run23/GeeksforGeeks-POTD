// Max Profit from Two Machines

/*
 *    1. We are given two machines A and B with task profits in arrays a[] and b[].
 *    2. Each task can be assigned to either machine, with limits x and y on tasks per machine.
 *    3. Since x + y ≥ n, all tasks can be assigned without leaving any unprocessed.
 *    4. To maximize profit, we sort tasks by absolute profit difference between a[i] and b[i].
 *    5. This ensures we prioritize tasks where the choice of machine matters most.
 *    6. We then greedily assign tasks to the machine with higher profit, respecting capacity limits.
 *    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(n) for storing differences.
 */

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        vector<pair<int, int>> diffs;
        
        for (int i = 0; i < n; ++i) {
            diffs.push_back({abs(a[i] - b[i]), i});
        }
        
        sort(diffs.rbegin(), diffs.rend());
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int currIdx = diffs[i].second;
            
            if (a[currIdx] > b[currIdx]) {
                if (x > 0) {
                    ans += a[currIdx];
                    x--;
                } else {
                    ans += b[currIdx];
                    y--;
                }
            } else {
                if (y > 0) {
                    ans += b[currIdx];
                    y--;
                } else {
                    ans += a[currIdx];
                    x--;
                }
            }
        }
        
        return ans;
    }
};


// Key Points
// 1. Tasks are sorted by absolute profit difference between machines.
// 2. Greedy assignment ensures maximum gain at each step.
// 3. Capacity limits x and y are respected during assignment.
// 4. Sorting guarantees we handle high-impact tasks first.
// 5. Each task is assigned exactly once since x + y ≥ n.
// 6. Works efficiently for n up to 1e5.
// 7. Alternative method: two max-heaps for a[] and b[] can also solve the problem.