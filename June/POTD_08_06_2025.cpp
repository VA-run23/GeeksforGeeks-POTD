/*
    1. The 'addStrings' function simulates integer addition by iterating over two strings digit-by-digit, handling carry, and reversing the result.
    2. The 'valSum' function checks if the sum of two given substrings matches the expected sum in the original string and continues recursively.
    3. The 'isSumString' function iterates through possible first and second numbers in the string, ensuring they don’t have leading zeros.
    4. It calls 'valSum' to verify whether the entire string follows the sum-string property recursively.
    5. The recursive process ensures that every number in the sequence is the sum of the previous two.
    6. The algorithm efficiently checks possible splits by iterating over different substring lengths, ensuring valid conditions.
    7. If a valid sum-string pattern is found, the function returns 'true'; otherwise, it returns 'false'.
*/


class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool valSum(string s, int start, string num1, string num2) {
        string sum = addStrings(num1, num2);
        int sumLen = sum.size();

        if (start + num1.size() + num2.size() + sumLen > s.size() || s.substr(start + num1.size() + num2.size(), sumLen) != sum) 
            return false;

        if (start + num1.size() + num2.size() + sumLen == s.size()) 
            return true;

        return valSum(s, start + num1.size(), num2, sum);
    }

    bool isSumString(string s) {
        int len = s.size();
        
        for (int m = 1; m < len; ++m) {
            string num1 = s.substr(0, m);
            if (num1[0] == '0' && num1.size() > 1) continue;

            for (int n = 1; m + n < len; ++n) {
                string num2 = s.substr(m, n);
                if (num2[0] == '0' && num2.size() > 1) continue;

                if (valSum(s, 0, num1, num2)) return true;
            }
        }
        return false;
    }
};