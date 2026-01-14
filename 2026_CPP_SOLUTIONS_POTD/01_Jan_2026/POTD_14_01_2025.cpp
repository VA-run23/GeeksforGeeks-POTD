/*
   1. The function takes an array of characters ('P' for police, 'T' for thief) and an integer k (max distance).
   2. It first scans the array and stores indices of police in one vector and thieves in another.
   3. Two pointers (i for police, j for thieves) are used to traverse both vectors simultaneously.
   4. If the current police and thief are within distance k, they are matched, and both pointers move forward.
   5. If the thief is too far left of the police, move the thief pointer forward to find a closer match.
   6. If the police is too far left of the thief, move the police pointer forward to find a closer match.
   7. The total number of successful matches (caught thieves) is returned as the result.
   Time Complexity: O(n) — single pass through the array plus linear matching.
   Space Complexity: O(n) — storing indices of police and thieves.
*/

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int> police, thieves;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') police.push_back(i);
            else if (arr[i] == 'T') thieves.push_back(i);
        }

        int i = 0, j = 0, caught = 0;
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                caught++;
                i++;
                j++;
            } else if (thieves[j] < police[i]) {
                j++;
            } else {
                i++;
            }
        }
        return caught;
    }
};