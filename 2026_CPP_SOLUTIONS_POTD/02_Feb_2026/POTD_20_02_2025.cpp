/*
    1. This code solves the "Form the Largest Number" problem by arranging integers to form the largest possible concatenated value.
    2. Each integer is first converted into a string for easier concatenation and comparison.
    3. The custom comparator ensures that for two strings a and b, the order is decided by comparing a+b and b+a.
    4. Sorting the array with this comparator guarantees that the concatenated result is maximized.
    5. If the largest element after sorting is "0", the entire result is simply "0" (to avoid leading zeros).
    6. Time Complexity: O(n log n * k), where n = number of elements and k = average string length.
    7. Space Complexity: O(n * k), due to storing string representations of all numbers.
*/

class Solution {
public:
    static bool compare(const string &a, const string &b) {
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        // code here
        vector<string> strArr;
        for (int num : arr)
            strArr.push_back(to_string(num));
        
        sort(strArr.begin(), strArr.end(), compare);

        if (strArr[0] == "0")
            return "0";

        string result = "";
        for (const string &s : strArr)
            result += s;

        return result;
    }
};

// Key points:
// - Convert integers to strings for concatenation-based comparison.
// - Use custom comparator to decide order based on combined string values.
// - Sorting ensures correct arrangement for maximum number.
// - Handle edge case where all numbers are zero.
// - Time complexity mainly comes from sorting with string comparisons.
// - Space complexity comes from storing string versions of integers.
// - Final result is built by concatenating sorted strings.
