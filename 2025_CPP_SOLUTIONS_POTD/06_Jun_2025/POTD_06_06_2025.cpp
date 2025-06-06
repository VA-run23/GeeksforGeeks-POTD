/*
    1. Initialize necessary variables for hashing, pattern length, and text length.
    2. Compute a rolling multiplier 'h' to maintain hash values efficiently.
    3. Calculate the initial hash values for the pattern and first window in the text.
    4. Slide the pattern over the text while updating hash values dynamically.
    5. If hash values match, verify the pattern manually to avoid false positives.
    6. Store the 1-based index positions where the pattern occurs.
    7. Ensure hash values remain non-negative for correctness.
*/


class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        vector<int> ans;
        int m = pat.size();
        int n = txt.size();
        int prime = 101;
        int patHash = 0, txtHash = 0, h = 1;

        for (int i = 0; i < m - 1; i++)
            h = (h * 26) % prime;

        for (int i = 0; i < m; i++) {
            patHash = (26 * patHash + pat[i]) % prime;
            txtHash = (26 * txtHash + txt[i]) % prime;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patHash == txtHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    ans.push_back(i + 1);
            }

            if (i < n - m) {
                txtHash = (26 * (txtHash - txt[i] * h) + txt[i + m]) % prime;
                if (txtHash < 0)
                    txtHash += prime;
            }
        }

        return ans;
    }
};