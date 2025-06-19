/*
    1. Traverse the input string and collect lowercase and uppercase characters separately into 'lower' and 'upper' vectors.
    2. Sort both vectors individually to get sorted lowercase and uppercase characters.
    3. Initialize two indices, 'l' and 'u', to track the current position in 'lower' and 'upper' vectors respectively.
    4. Iterate through the original string again to reconstruct a new string.
    5. For every character, if it was lowercase, replace it with the next sorted lowercase character; else replace with the next uppercase.
    6. This preserves the original case position while sorting letters of the same case.
    7. Time Complexity: O(N log N) due to sorting; Space Complexity: O(N) for storing characters separately and the result.
*/

class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<char> lower, upper;
        for (char c : s) {
            if (islower(c)) lower.push_back(c);
            else upper.push_back(c);
        }

        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        int l = 0, u = 0;
        string result = s;
        for (int i = 0; i < s.size(); ++i) {
            if (islower(s[i])) result[i] = lower[l++];
            else result[i] = upper[u++];
        }

        return result;
    }
};