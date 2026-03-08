/*
    1. This function checks if any three numbers in the array form a Pythagorean triplet (a² + b² = c²).
    2. It first inserts all elements into an unordered_set for O(1) lookup.
    3. The maximum value in the array is found to limit the search space.
    4. For each pair (i, j) present in the array, it computes val = i² + j².
    5. It then checks if sqrt(val) exists in the array and matches exactly (x² == val).
    6. Time Complexity: O(n²) in worst case, since we iterate over pairs (i, j).
    7. Space Complexity: O(n), due to storing elements in the unordered_set.
*/

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> s(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
        for (int i = 1; i < maxVal; i++) {
            if (s.count(i)) {
                for (int j = 1; j < maxVal; j++) {
                    if (s.count(j)) {
                        int val = i * i + j * j;
                        int x = sqrt(val);
                        if (s.count(x) && x * x == val) return true;
                    }
                }
            }
        }
        return false;
    }
};

// Key points:
// - Array size can be up to 1e5, but values are capped at 1e3.
// - This mismatch allows an O(n²) approach since the value range is small.
// - Using a set ensures constant-time lookups.
// - The algorithm leverages the constraint that values are limited, making pairwise checks feasible.
// - The sqrt check ensures exact integer matches for c.
// - This approach balances efficiency with correctness given the constraints.
