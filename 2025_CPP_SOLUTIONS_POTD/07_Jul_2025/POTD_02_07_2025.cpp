/*
    1. This function finds the length of the longest contiguous subarray 
    containing at most 2 distinct integers using the sliding window technique.
    2. Two pointers 'i' (start) and 'j' (end) define the window boundaries as it expands and shrinks.
    3. The 'unordered_map' 'mp' keeps track of the frequency of elements inside the current window.
    4. When the window contains more than 2 distinct elements, it shrinks from the left ('i' advances) 
    and elements are removed from the map accordingly.
    5. For each valid window (with ≤ 2 distinct elements), the maximum length is tracked using 'mx'.
    6. The function returns the maximum length of such a subarray found during the traversal.
    7. Time Complexity: O(n), since each element is added and removed from the map at most once. 
    Space Complexity: O(1), as the map holds at most 3 keys (in worst case, briefly before shrinking).
*/

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int mx = INT_MIN;

        while (j < n) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }

        return mx;
    }
};
