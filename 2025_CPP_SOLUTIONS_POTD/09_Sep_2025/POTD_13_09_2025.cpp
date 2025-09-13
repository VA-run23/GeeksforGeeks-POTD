/*
    1. This function calculates the minimum cost to cut a board into squares using greedy strategy.
    2. It sorts the vertical (x) and horizontal (y) cut costs in descending order to prioritize expensive cuts early.
    3. It maintains counters for horizontal and vertical segments (hSeg and vSeg) to track how many pieces each cut affects.
    4. In each iteration, it picks the higher cost cut (either vertical or horizontal) and updates the total cost accordingly.
    5. After one list is exhausted, it processes the remaining cuts in the other list, multiplying by the current segment count.
    6. This greedy approach ensures that expensive cuts are applied when they affect fewer segments, minimizing overall cost.
    7. Time Complexity: O(n log n + m log m) due to sorting; Space Complexity: O(1) as no extra space is used beyond variables.
*/

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hSeg = 1, vSeg = 1;
        int totalCost = 0;
        
        while(i < x.size() && j < y.size()) {
            if(x[i] >= y[j]) {
                totalCost += x[i] * hSeg;
                vSeg++;
                i++;
            } else {
                totalCost += y[j] * vSeg;
                hSeg++;
                j++;
            }
        }
        while(i < x.size()) {
            totalCost += x[i] * hSeg;
            vSeg++;
            i++;
        }
        while(j < y.size()) {
            totalCost += y[j] * vSeg;
            hSeg++;
            j++;
        }
        return totalCost;
    }
};