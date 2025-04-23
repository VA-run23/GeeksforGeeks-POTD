// This code finds two unique numbers in an array where all other numbers appear in pairs.
// Step 1: XOR all numbers to compute x, which is the XOR of the two unique numbers.
// Step 2: Find the position of the first set bit in x, called pos, to distinguish between the two numbers.
// Step 3: Divide the numbers into two groups based on the bit at pos and XOR within each group to isolate the unique numbers.
// Step 4: Use XOR results from both groups to determine the two unique numbers, a and b.
// Step 5: Return the two unique numbers in sorted order using min() and max().
// Time Complexity: O(n), as we traverse the array three times.
// Space Complexity: O(1), as no additional data structures are used.

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int x = 0, setBit = 0, pos = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            x = x ^ arr[i];
        }

        int temp = x;
        while ((temp & 1) == 0) {
            pos++;
            temp = temp >> 1;
        }

        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if ((arr[i] >> pos) & 1) {
                a = a ^ arr[i];
            } else {
                b = b ^ arr[i];
            }
        }
        return {min(a, b), max(a, b)};
    }
};