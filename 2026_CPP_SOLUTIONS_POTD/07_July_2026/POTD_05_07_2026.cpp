// Maximum Number of Characters Between Any Two Same Character

/*
 *    1. We need to find the maximum gap between two identical characters in a string.
 *    2. Use an array to store the first occurrence index of each character.
 *    3. Traverse the string and update the maximum gap whenever a repeated character is found.
 *    4. If a character is seen for the first time, record its index.
 *    5. The gap is calculated as the difference between current index and first occurrence index.
 *    6. Subtract 1 to count only the characters in between, not including the endpoints.
 *    7. Time Complexity: O(n), Space Complexity: O(26) ≈ O(1).
 */

class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int>seen(26, -1);
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(seen[s[i]-'a'] == -1){
                seen[s[i]-'a'] = i;
            }
            ans = max(ans, i - seen[s[i] - 'a']);
        }
        return ans == 0 ? -1 : ans - 1;
    }
};

// Key Points
// 1. Initialize an array of size 26 with -1 to track first occurrences.
// 2. Traverse the string once, ensuring O(n) time complexity.
// 3. Record the first occurrence index when a character is seen for the first time.
// 4. For repeated characters, compute the gap using current index - first occurrence.
// 5. Subtract 1 to exclude the characters themselves from the gap count.
// 6. Return -1 if no repeating characters are found.
// 7. Space complexity remains constant since only 26 slots are used.