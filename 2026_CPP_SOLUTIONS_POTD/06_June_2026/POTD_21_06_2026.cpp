// Choose and Swap

/*
 *    1. The problem requires swapping two distinct characters in a string.
 *    2. The swap should be chosen to make the string lexicographically smallest.
 *    3. We track characters using a map to identify potential swaps.
 *    4. The first beneficial swap is selected by comparing characters.
 *    5. Once identified, all occurrences of the two characters are swapped.
 *    6. If no beneficial swap exists, the string remains unchanged.
 *    7. Time Complexity: O(n * m), Space Complexity: O(m), where n = string length and m = distinct characters.
 */

class Solution {
public:
    string chooseSwap(string& s) {
        // code here
        map<char, pair<bool, bool>> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]] = {true, false};
        }
        int i = 0;
        char y = '#';
        char z = '#';
        bool check = false;
        while (i < s.size()) {
            char c = s[i];
            for (auto it : map) {
                char x = it.first;
                bool a = it.second.first;
                bool b = it.second.second;
                if (x < c && a && !b) {
                    y = x;
                    z = s[i];
                    check = true;
                    break;
                }
            }
            if (check)
                break;
            map[s[i]] = {true, true};
            i++;
        }
        if (i >= s.size())
            return s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == y)
                s[i] = z;
            else if (s[i] == z)
                s[i] = y;
        }
        return s;
    }
};

// Key Points
// 1. The goal is to minimize the string lexicographically.
// 2. A map tracks character presence and usage.
// 3. The first valid swap is chosen greedily.
// 4. Swapping is done globally across the string.
// 5. If no swap improves the string, it remains unchanged.
// 6. Complexity depends on string length and distinct characters.
// 7. Greedy approach ensures correctness with minimal effort.