/*
    1. Check if the array size is divisible by k — if not, forming equal groups is impossible.
    2. Use a multiset to store all elements in sorted order and allow duplicates.
    3. Continuously take the smallest element as the start of a group.
    4. Try to find k consecutive integers starting from that smallest element.
    5. If any required consecutive element is missing, return false immediately.
    6. If found, erase those k elements from the multiset and continue.
    7. Repeat until all elements are grouped successfully; return true if complete.

    Time Complexity: O(n log n), due to multiset insertions and lookups for each of the n elements.
    Space Complexity: O(n), for storing n elements in the multiset.
*/

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        if (arr.size() % k != 0) return false;
        multiset<int> ms(arr.begin(), arr.end());

        while (!ms.empty()) {
            int first = *ms.begin();
            for (int i = 0; i < k; ++i) {
                auto it = ms.find(first + i);
                if (it == ms.end()) return false;
                ms.erase(it);
            }
        }
        return true;
    }
};
