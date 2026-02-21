/*
    1. This function calculates the H-Index of a researcher based on citation counts.
    2. It first sorts the citations array in descending order using 'sort' with 'greater<int>()'.
    3. The variable 'h' tracks the maximum H-Index found during iteration.
    4. For each paper at index 'i', it checks if citations[i] >= i+1 (meaning at least i+1 papers have i+1 citations).
    5. If true, 'h' is updated to i+1; otherwise, the loop breaks since further values will be smaller.
    6. Finally, the function returns 'h', which represents the highest valid H-Index.
    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) since sorting is in-place.
*/
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h = i + 1;
            } else {
                break;
            }
        }
        return h;
    }
};

// Key points:
// - Sort citations in descending order.
// - Iterate through sorted list to check if citations[i] >= i+1.
// - Update h-index accordingly until condition fails.
// - Sorting dominates time complexity (O(n log n)).
// - Space usage is constant (O(1)) since sorting is in-place.
// - The algorithm ensures correctness by leveraging sorted order.
// - Break early when condition fails to avoid unnecessary checks.
