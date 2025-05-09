/*
    1. The function findMaxHelper recursively explores swaps to maximize the number.
    2. It identifies the largest possible digit beyond index and attempts swapping.
    3. If a swap occurs, the remaining swaps (k) are reduced.
    4. After swapping, it checks if the new number is greater than the previous max.
    5. The function uses recursion to explore further swaps and backtracks after each attempt.
    6. The main function findMaximumNum initializes maxNum and invokes the helper function.
    7. Time Complexity: O((n²)^k) due to recursive swaps; Space Complexity: O(n) for recursion stack.
*/


class Solution {
  public:
  
  void findMaxHelper(string &s, int k, int index, string &maxNum) {
        if (k == 0) return;

        char maxChar = s[index];
        for (int i = index + 1; i < s.size(); i++) {
            if (s[i] > maxChar) {
                maxChar = s[i];
            }
        }

        if (maxChar != s[index]) {
            k--;
        }

        for (int i = index; i < s.size(); i++) {
            if (s[i] == maxChar) {
                swap(s[index], s[i]);
                if (s.compare(maxNum) > 0) {
                    maxNum = s;
                }
                findMaxHelper(s, k, index + 1, maxNum);
                swap(s[index], s[i]);
            }
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string maxNum = s;
        findMaxHelper(s, k, 0, maxNum);
        return maxNum;
    }
};
