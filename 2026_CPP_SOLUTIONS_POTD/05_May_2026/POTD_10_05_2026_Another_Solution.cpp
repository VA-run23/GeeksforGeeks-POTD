// Max Profit from Two Machines

/*
 *    1. We are given two machines A and B with task profits in arrays a[] and b[].
 *    2. Each machine has a capacity limit: A can process at most x tasks, B at most y tasks.
 *    3. Since x + y ≥ n, all tasks can be assigned without leaving any unprocessed.
 *    4. We use two max-heaps: one prioritizing tasks for A, one for B, based on profit differences.
 *    5. At each step, we pick the best available option from heaps, respecting machine limits.
 *    6. We mark tasks as taken to avoid duplication and continue until all tasks are assigned.
 *    7. Time Complexity: O(n log n) due to heap operations; Space Complexity: O(n) for heaps and tracking.
 */

class Solution {
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        
        priority_queue<pair<int, int>> heapA, heapB;
        for(int i = 0; i < n; i++) {
            heapA.push({a[i] - b[i], i});
            heapB.push({b[i] - a[i], i});
        }
        
        vector<bool> taken(n, false);
        long long ans = 0;
        
        while(x > 0 || y > 0) {
            while(!heapA.empty() && taken[heapA.top().second]) heapA.pop();
            while(!heapB.empty() && taken[heapB.top().second]) heapB.pop();
            
            if(heapA.empty() && heapB.empty()) break;
            
            int bestA = heapA.empty() ? -1000000 : heapA.top().first;
            int bestB = heapB.empty() ? -1000000 : heapB.top().first;
            
            if(bestA >= bestB) {
                int currIdx = heapA.top().second;
                if(x > 0) {
                    ans += a[currIdx];
                    x--;
                } else {
                    ans += b[currIdx];
                    y--;
                }
                taken[currIdx] = true;
                heapA.pop();
            } else {
                int currIdx = heapB.top().second;
                if(y > 0) {
                    ans += b[currIdx];
                    y--;
                } else {
                    ans += a[currIdx];
                    x--;
                }
                taken[currIdx] = true;
                heapB.pop();
            }
        }
        return ans;
    }
};

// Key Points
// 1. Two max-heaps are built to prioritize tasks for each machine.
// 2. Each heap stores profit difference and task index.
// 3. At each step, the best available option is chosen.
// 4. Capacity limits x and y are respected during assignment.
// 5. Tasks are marked as taken to avoid duplication.
// 6. Ensures all tasks are assigned since x + y ≥ n.
// 7. Alternative optimal method: greedy sorting by absolute profit difference.