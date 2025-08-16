/*
    1. The function converts all integers in the input array to strings to facilitate custom sorting based on concatenation.
    2. It uses a static comparator that sorts strings such that a + b is greater than b + a, ensuring the largest number is formed.
    3. The sorted strings are then concatenated to form the final result.
    4. If the largest number starts with '0', it means all numbers were zero, so it returns "0".
    5. The use of vector<string> allows dynamic storage and manipulation of string representations of numbers.
    6. Time Complexity: O(n log n), due to sorting n elements with a custom comparator.
    7. Space Complexity: O(n), for storing string representations of the input integers.
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