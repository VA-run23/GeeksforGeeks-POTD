// Lexicographically Smallest After Removing K

/*
 *    1. The problem requires removing k characters to form the smallest lexicographic string.
 *    2. If the string length is a power of 2, k is halved; otherwise, k is doubled.
 *    3. If k becomes greater than or equal to the string length, return "-1".
 *    4. Use a stack-like approach to greedily remove larger characters when possible.
 *    5. Iterate through the string, popping from the stack if the current character is smaller.
 *    6. If k remains after traversal, remove characters from the end of the stack.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
public:
    string lexicographicallySmallest(string& s, int k) {
        // code here
        int n = s.size();

        if ((n & (n - 1)) == 0)
            k /= 2;
        else
            k *= 2;

        if (k >= n)
            return "-1";
        vector<char> st;
        for (char ch : s) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        while (k > 0) {
            st.pop_back();
            k--;
        }
        string ans(st.begin(), st.end());
        return ans.empty() ? "-1" : ans;
    }
};

// Key Points
// 1. Adjust k based on whether n is a power of 2.
// 2. Return "-1" if k >= n.
// 3. Use a greedy stack-based approach.
// 4. Pop larger characters when a smaller one appears.
// 5. Remove remaining characters from the end if k > 0.
// 6. Construct the final string from the stack.
// 7. Efficient solution with O(n) time and space.