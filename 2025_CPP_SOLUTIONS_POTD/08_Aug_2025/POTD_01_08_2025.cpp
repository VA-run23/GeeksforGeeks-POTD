/*
    1. We initialize a hash map 'freq' to count how many times each prefix sum has occurred, starting with freq[0] = 1.
    2. For each string in the array, we calculate a net value: +1 for each vowel, -1 for each consonant.
    3. We accumulate this net value into 'prefixSum', which represents the total balance up to the current string.
    4. If the same 'prefixSum' has occurred before, it means the substring between those positions is balanced.
    5. We add 'freq[prefixSum]' to 'ans' to count all such balanced substrings ending at the current position.
    6. We then increment 'freq[prefixSum]' to record this new occurrence for future substrings.
    7. Time Complexity: O(n), Space Complexity: O(n), where n is the number of strings in the array.
*/

class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefixSum = 0;
        int ans = 0;

        for (const string& s : arr) {
            int val = 0;
            for (char ch : s) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    val++;
                } else {
                    val--;
                }
            }

            prefixSum += val;
            ans += freq[prefixSum]; 
            freq[prefixSum]++;
        }

        return ans;
    }
};
