/*
    1. This function solves the Josephus problem using an iterative recurrence relation instead of recursion.  
    2. Base case: when only one person remains, survivor index = 0 (0-based).  
    3. The loop runs from i = 2 to n, progressively recalculating survivor position as circle size grows.  
    4. Formula used: res = (res + k) % i, which shifts survivor index by k steps and wraps around with modulus i.  
    5. The modulus is taken with respect to i (current circle size), not n, because eliminated people are excluded from counting.  
    6. After the loop, res holds the 0-based survivor index; adding 1 converts it to 1-based indexing.  
    7. Time Complexity = O(n) (single loop), Space Complexity = O(1) (constant extra space).  
*/

/* Key Points (based on your queries):
- Eliminated people are not included in further counting; recurrence shrinks circle size each step.
- '% i' is correct because survivor position is recalculated relative to the current group size.
- Simulation with vectors is possible, but recurrence/iterative formula is more efficient.
*/

class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + k) % i;
        }
        return res + 1; 
    }
};