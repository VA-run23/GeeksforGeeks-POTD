/*
    1. This class 'Solution' solves the "Ways to Tile a Floor" problem using memoized recursion based on the Fibonacci sequence.
    2. The 'fiboDP' vector stores precomputed results to avoid redundant calculations (dynamic programming).
    3. The constructor 'Solution()' initializes 'fiboDP' with size 46 and sets base cases: fiboDP[0] = 1 and fiboDP[1] = 1.
    4. The function 'numberOfWays(int n)' returns the number of ways to tile a 2×n floor using 2×1 tiles.
    5. If 'fiboDP[n]' is already computed (non-zero), it returns the cached value to save time.
    6. Otherwise, it recursively computes 'numberOfWays(n-1) + numberOfWays(n-2)' and stores the result in 'fiboDP[n]'.
    7. This recurrence is identical to the Fibonacci sequence, where each state depends on the previous two.
*/

// Time Complexity: O(n) — Each value from 0 to n is computed only once.
// Space Complexity: O(n) — Due to the memoization array 'fiboDP'.


class Solution {
  public:
    vector<int> fiboDP;

    Solution() {
        fiboDP.resize(46, 0); 
        fiboDP[0] = 1;
        fiboDP[1] = 1;
    }
    int numberOfWays(int n) {
        // code here
        if(fiboDP[n])return fiboDP[n];

        fiboDP[n]= numberOfWays(n-1) + numberOfWays(n -2);
        return fiboDP[n];
    }
};