/*
    1. Count the frequency of each character in the input string 's' using a 26-size array (since only lowercase letters).
    2. Sort the frequency array in decreasing order to bring the most frequent character to the front.
    3. For 'k' times, decrement the most frequent character and bubble it down if needed to maintain descending order.
    4. This greedy approach minimizes value by always reducing the largest frequency available first.
    5. After 'k' removals, compute the final value by summing the squares of the remaining frequencies.
    6. Time complexity is O(n + 26 log 26 + k*26) ≈ O(n + k), where n is the string length — efficient for n ≤ 10⁵.
    7. Space complexity is O(1) since only fixed 26-space vector is used for lowercase letters.
*/

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n = s.size();
        int ans = 0;
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        while (k-- > 0 && freq[0] > 0) {
            freq[0]--;
            int j = 0;
            while (j + 1 < 26 && freq[j] < freq[j + 1]) {
                swap(freq[j], freq[j + 1]);
                j++;
            }
        }

        for (int i = 0; i < 26; i++) {
            ans += freq[i] * freq[i];
        }

        return ans;
    }
};