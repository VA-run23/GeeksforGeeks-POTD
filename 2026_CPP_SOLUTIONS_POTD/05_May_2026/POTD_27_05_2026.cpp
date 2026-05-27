// Wifi Range

/*
 *    1. The problem checks if all houses are covered by WiFi routers.
 *    2. Each router has a coverage range of x units to the left and right.
 *    3. We iterate through the string to find positions of routers ('1').
 *    4. For the first router, ensure it covers the initial segment.
 *    5. For consecutive routers, ensure the gap between them is not too large.
 *    6. Finally, check if the last router covers the end segment.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
    public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();
        int last = -1;
        for (int i = 0; i<n; i++) {
            if (s[i] == '1') {
                
                if (last == -1) {
                    if (i>x)
                        return false;
                }
                else {
                    if ((i - last - 1) > 2*x)
                        return false;
                }
                last = i;
            }
            
        }
        if (last == -1)
            return false;
        if (n - 1-last >x)
            return false;
        
        return true;
    }
};

// Key Points
// 1. Routers are represented by '1' in the string.
// 2. Each router covers x units to both sides.
// 3. The first router must cover the start of the string.
// 4. Gaps between routers must not exceed 2*x.
// 5. The last router must cover the end of the string.
// 6. If no router exists, return false.
// 7. Efficient solution with O(n) time and O(1) space.