/*
    1) Uses the Z-algorithm: z[i] is the length of the longest substring starting at i that matches the prefix.
    2) Maintains a Z-box [l, r] to reuse previous matches; initializes z[0] = n and extends when possible.
    3) If i <= r, seeds z[i] with min(r - i + 1, z[i - l]) to skip already-known matches.
    4) Then compares s[z[i]] with s[i + z[i]] and post-increments z[i] (z[i]++) while they match.
    5) Updates the Z-box to [i, i + z[i] - 1] when the current match extends beyond r.
    6) Scans i from n-1 down to 1; if z[i] >= n - i, returns i (matching prefix length is n - i); else -1.
    7) Time Complexity: O(n) due to linear Z-construction and scan; Space Complexity: O(n) for the z array.
*/

class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size();
        if (n <= 1) return -1;

        vector<int> z(n, 0);
        z[0] = n;
        
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) 
                z[i] = min(r - i + 1, z[i - l]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        for (int i = n - 1; i >= 1; --i) {
            if (z[i] >= n - i)
                return i;
        }
        return -1;
    }
};
