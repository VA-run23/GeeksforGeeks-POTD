/*
    1. The function calculates the H-index, which is the maximum number h such that the researcher has h papers with at least h citations each.
    2. It first sorts the citations array in descending order using 'sort' with 'greater<int>()' to prioritize highly cited papers.
    3. It initializes 'h = 0' and iterates through the sorted array to find the largest 'i + 1' such that 'citations[i] >= i + 1'.
    4. If the current paper has citations ≥ its position index + 1, it updates 'h'; otherwise, it breaks the loop.
    5. This ensures that only the maximum valid H-index is returned, satisfying the definition.
    6. Time complexity is O(n log n) due to sorting, where n is the number of papers.
    7. Space complexity is O(1) if sorting is in-place; otherwise, O(n) depending on the sort implementation.
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