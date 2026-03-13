// Generate IP Addresses

/*
 *    1. The problem requires generating all valid IP addresses from a given string.
 *    2. An IP address consists of four segments separated by dots.
 *    3. Each segment must be between 0 and 255, with no leading zeros unless the segment is "0".
 *    4. The string length must be between 4 and 12 characters to form a valid IP.
 *    5. We iterate over possible segment lengths (1–3) for the first three parts.
 *    6. The fourth part is determined by the remaining characters.
 *    7. Time Complexity: O(n^3) due to nested loops; Space Complexity: O(n) for storing results.
 */

class Solution {
public:
    vector<string> generateIp(string& s) {
        // code here
        vector<string> ans;
        int n = s.size();
        
        if (n < 4 || n > 12) return ans;
        
        for (int a = 1; a <= 3 && a < n; a++) {
            for (int b = 1; b <= 3 && a + b < n; b++) {
                for (int c = 1; c <= 3 && a + b + c < n; c++) {
                    int d = n - a - b - c;
                    
                    if (d > 0 && d <= 3) {
                        if (isValid(s, 0, a) && 
                            isValid(s, a, b) && 
                            isValid(s, a + b, c) && 
                            isValid(s, a + b + c, d)) {
                            
                            ans.push_back(
                                s.substr(0, a) + "." +
                                s.substr(a, b) + "." +
                                s.substr(a + b, c) + "." +
                                s.substr(a + b + c, d)
                            );
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
private:
    bool isValid(const string& s, int start, int len) {
        if (len > 1 && s[start] == '0') return 0;
        
        int val = 0;
        for (int i = start; i < start + len; i++) {
            val = val * 10 + (s[i] - '0');
        }
        
        return val <= 255;
    }
};

// Key Points
// 1. IP addresses must have exactly 4 segments.
// 2. Each segment length can be 1–3 digits.
// 3. Leading zeros are invalid except for "0" itself.
// 4. Segment values must be between 0 and 255.
// 5. String length must be between 4 and 12.
// 6. Brute force tries all segment splits using nested loops.
// 7. Time complexity is O(n^3), space complexity O(n).
