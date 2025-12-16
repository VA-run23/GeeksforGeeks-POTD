/*
    1. First, the function checks if the lengths of s1 and s2 are equal; if not, they cannot be rotations.
    2. If lengths differ, it immediately returns false since rotation requires equal-sized strings.
    3. Next, it creates a new string t by concatenating s1 with itself (s1+s1).
    4. This trick works because any rotation of s1 must appear as a substring within s1+s1.
    5. The function then searches for s2 inside t using the find() method.
    6. If s2 is found, find() returns a valid index less than t.length(), so the function returns true.
    7. Otherwise, if s2 is not found, find() returns npos (a large value), making the condition false.

    Time Complexity: O(n) → where n is the length of the string, since find() runs in linear time.
    Space Complexity: O(n) → extra space is used to store the concatenated string t (size 2n).
*/

/* 🔑 Key Points:
- Rotation check is simplified by concatenating s1 with itself.
- No need for manual shifting or recursion; substring search suffices.
- Elegant one-liner: return (s1+s1).find(s2) < (s1+s1).length();
- Compared to mutual recursion, this approach is more efficient and concise.
- Mutual recursion is useful for practice, but in real-world coding, the concatenation trick is optimal.
*/

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if (s1.length() != s2.length())
        return false;

        string t = s1 + s1;
        return t.find(s2) < t.length();
    }
};  