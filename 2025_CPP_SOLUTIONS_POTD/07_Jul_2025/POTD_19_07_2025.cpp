/*
    1. The function counts the occurrences of each vowel (a, e, i, o, u) in the input string 's' using a vector of size 5.
    2. It then calculates how many unique vowels are present ('vl') and the product of their individual counts ('ians').
    3. If no vowel is present, the function returns 0.
    4. Otherwise, it computes 'vl!' (factorial of number of unique vowels) which represents the number of permutations of selected vowels.
    5. The result is 'vl! * ians', which accounts for all distinct ways to choose one occurrence per vowel and arrange them.
    6. Time Complexity: O(n + v) = O(n), where n = length of string and v = number of unique vowels (max 5).
    7. Space Complexity: O(1) — constant space for the vowel count vector and integer variables.
*/

class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        vector<int> vowels(5, 0);

        for (char c : s) {
            switch (c) {
                case 'a': vowels[0]++; break;
                case 'e': vowels[1]++; break;
                case 'i': vowels[2]++; break;
                case 'o': vowels[3]++; break;
                case 'u': vowels[4]++; break;
            }
        }

        int vl = 0;
        int ians = 1;
        

        for (int i = 0; i < 5; i++) {
            if (vowels[i] > 0) {
                vl++;
                ians *= vowels[i]; 
            }
        }
        if (vl == 0) return 0;

        int fact = 1;
        for (int i = 2; i <= vl; ++i) {
            fact *= i;
        }
        

        return fact * ians;
    }
};