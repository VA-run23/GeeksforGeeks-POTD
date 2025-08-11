/*
    1. This code finds the maximum sum of lengths of two non-overlapping odd-length palindromes in a string using Manacher's algorithm.
    2. It first computes the radius of the largest odd palindrome centered at each index using 'manacherOdd'.
    3. Then, it sweeps left-to-right to compute the best palindrome ending at each position using a max-heap of linear contributions.
    4. Similarly, it sweeps right-to-left to compute the best palindrome starting at each position using another max-heap.
    5. Prefix and suffix maximum arrays ('maxPref' and 'maxSuff') are built to store the best palindrome lengths ending before or starting after each index.
    6. Finally, it iterates through all split points to find the maximum sum of two non-overlapping palindromes.
    7. Time Complexity: O(n), Space Complexity: O(n), where n is the length of the string.
*/

class Solution {
  public:
    int maxSum(string &s) {
        // code here
        
        int n = s.size();
        if (n < 2) return 0;

        vector<int> d = manacherOdd(s);

        vector<int> maxEnd(n, 0);   
        vector<int> maxStart(n, 0); 


        priority_queue<pair<int,int>> pq;
        int centerIdx = 0;
        for (int e = 0; e < n; e++) {
            while (centerIdx < n && centerIdx <= e) {
                int c = centerIdx;
                int B = 1 - 2 * c;          
                int R = c + d[c] - 1;       
                pq.push({B, R});
                centerIdx++;
            }
            while (!pq.empty() && pq.top().second < e) pq.pop();
            if (!pq.empty()) {
                maxEnd[e] = 2 * e + pq.top().first; 
            } else {
                maxEnd[e] = 1;
            }
        }


        vector<int> maxPref(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (maxEnd[i] > cur) cur = maxEnd[i];
            maxPref[i] = cur;
        }


        priority_queue<pair<int,int>> pq2; 
        int centerIdx2 = n - 1;
        for (int sIdx = n - 1; sIdx >= 0; sIdx--) {
            while (centerIdx2 >= 0 && centerIdx2 >= sIdx) {
                int c = centerIdx2;
                int C = 2 * c + 1;
                int L = c - d[c] + 1;
                pq2.push({C, L});
                centerIdx2--;
            }
            while (!pq2.empty() && pq2.top().second > sIdx) pq2.pop();
            if (!pq2.empty()) {
                maxStart[sIdx] = -2 * sIdx + pq2.top().first;
            } else {
                maxStart[sIdx] = 1;
            }
        }


        vector<int> maxSuff(n);
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (maxStart[i] > cur) cur = maxStart[i];
            maxSuff[i] = cur;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, maxPref[i] + maxSuff[i + 1]);
        }
        return ans;
    }

private:
    vector<int> manacherOdd(const string &s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = 1;
            if (i <= r) k = min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return d;
    }
};
