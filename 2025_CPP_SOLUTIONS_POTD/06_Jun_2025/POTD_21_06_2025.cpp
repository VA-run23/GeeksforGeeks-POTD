/*
    1. We iterate through the array and store indices of 'P' (police) and 'T' (thieves) in two separate queues.
    2. For every new element, we push the index into the appropriate queue based on whether it's a policeman or thief.
    3. When both queues are non-empty, we compare the indices at the front to check if the distance is within range 'k'.
    4. If the distance condition is satisfied, we increment the count and remove one police and one thief from their queues.
    5. If not, we discard the one that’s further left (whichever comes earlier in the array) since no match is possible for it.
    6. This greedy matching ensures we catch as many thieves as possible, giving us the maximum pairs.
    7. Time Complexity: O(n); Space Complexity: O(n) — for maintaining the queues storing indices.
*/

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        queue<int> police, thieves;
        int n = arr.size(), caught = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push(i);
            else if (arr[i] == 'T')
                thieves.push(i);

            while (!police.empty() && !thieves.empty()) {
                if (abs(police.front() - thieves.front()) <= k) {
                    caught++;
                    police.pop();
                    thieves.pop();
                } else if (thieves.front() < police.front()) {
                    thieves.pop();
                } else {
                    police.pop();
                }
            }
        }

        return caught;
    }
};