/*
    * This function calculates the sum of all possible substrings of a number represented as a string.
    * 'prev' stores the sum contribution from substrings ending at index i, updated iteratively.
    * Each digit contributes to multiple substrings, scaled based on its position in the string.
    * Formula: prev = prev * 10 + (s[i] - '0') * (i + 1), ensuring efficient calculation in O(n) time.
    * 'Total' accumulates the overall sum of all substrings for the given number.
    * The loop iterates through the string, updating 'prev' and summing up the contributions.
    * Finally, the function returns 'Total', which holds the sum of all substrings.
*/

class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
        long long Total = 0, prev = 0;
        
        for (int i = 0; i < n; i++) {
            prev = prev * 10 + (s[i] - '0') * (i + 1);
            Total += prev;
        }
        
        return Total;
    }
};
