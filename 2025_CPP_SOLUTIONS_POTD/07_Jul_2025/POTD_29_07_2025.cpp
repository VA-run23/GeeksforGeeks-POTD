/*
    1. Compute prefix sum of ASCII values using 1-based indexing: pSum[i + 1] = pSum[i] + s[i]
    2. Track first and last positions of each character using firstSeen and lastSeen arrays
    3. For each character that appears more than once (i.e., first < last), calculate range
    4. Set left as firstSeen + 1 to exclude the first occurrence; right is lastSeen
    5. Compute the ASCII sum of characters strictly between first and last using pSum
    6. Only include non-zero sums in the result vector
    7. Time Complexity: O(n + 26) = O(n); Space Complexity: O(n + 26) = O(n)
*/

class Solution {
  public:
    vector<int> asciirange(string& s) {
        // Code here
        int n = s.size();
        vector<int> firstSeen(26, -1), lastSeen(26, -1);
        vector<int> pSum(n + 1, 0), ans;

        for (int i = 0; i < n; ++i)
            pSum[i + 1] = pSum[i] + s[i];  

        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (firstSeen[idx] == -1)
                firstSeen[idx] = i;
            lastSeen[idx] = i;
        }

        for (int ch = 0; ch < 26; ++ch) {
            if (firstSeen[ch] != -1 && firstSeen[ch] < lastSeen[ch]) {
                int left = firstSeen[ch] + 1;
                int right = lastSeen[ch];
                int sum = pSum[right] - pSum[left];
                if (sum > 0)
                    ans.push_back(sum);
            }
        }

        return ans;
    }
};
