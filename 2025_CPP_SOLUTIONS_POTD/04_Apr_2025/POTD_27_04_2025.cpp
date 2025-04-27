// This code multiplies two large numbers represented as strings without converting them to integers.
// It handles negative signs using XOR logic and removes them from input strings for simplified processing.
// Each digit of the strings is multiplied, and the result is stored in a vector to manage carry and intermediate sums.
// The result vector has size m + n to ensure sufficient space for all carry operations during multiplication.
// Leading zeros are skipped while forming the final result string, and "0" is returned if the result is empty.
// Time Complexity: O(n * m), as each digit of one string is multiplied with all digits of the other.
// Space Complexity: O(n + m), due to the use of the result vector for storing intermediate sums.


class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        bool isNegative = (s1[0] == -) ^ (s2[0] == -);
        if (s1[0] == -) s1 = s1.substr(1);
        if (s2[0] == -) s2 = s2.substr(1);

        int m = s1.size(), n = s2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (s1[i] - 0) * (s2[j] - 0);
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) ans += (num + 0);
        }

        if (ans.empty()) return "0";

        return isNegative ? "-" + ans : ans;
    }
};