/*
    1. Calculate the length of the string and initialize a frequency array to count occurrences of each character.
    2. Iterate through the string to populate the frequency array.
    3. Compute the total number of possible swaps using the formula n * (n - 1) / 2.
    4. Initialize a variable to count duplicate swaps where swapping results in the same string.
    5. Iterate through the frequency array to compute duplicate swaps using f * (f - 1) / 2 for each character.
    6. Subtract duplicate swaps from total swaps and add 1 if there was at least one duplicate swap.
    7. Return the final count of distinct strings that can be obtained by exactly one swap.
*/

class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        long long swaps = 1LL * n * (n - 1) / 2;
        long long dupSwaps = 0;

        for (int f : freq) {
            dupSwaps += 1LL * f * (f - 1) / 2;
        }
        return (int)(swaps - dupSwaps + (dupSwaps > 0 ? 1 : 0));
    }
};
