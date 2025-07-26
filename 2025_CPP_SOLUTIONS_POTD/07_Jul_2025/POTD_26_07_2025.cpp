/*
    1. Traverse the input array and count the frequency of each element using an unordered_map called freq.
    2. For every element, after updating its frequency, check if it crosses the n/3 threshold.
    3. If it does, insert the element into a set to ensure uniqueness and sorted order later.
    4. Sets automatically avoid duplicates and help maintain ascending order during result preparation.
    5. After the loop, convert the set into a vector to match the return type and required format.
    6. This approach handles multiple majority elements efficiently and avoids extra sorting logic.
    7. Time Complexity: O(n); Space Complexity: O(n) — due to frequency map and result set.
*/

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here

        int n = arr.size();
        set<int> ans;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            freq[arr[i]]++;
            if (freq[arr[i]] > n / 3) {
                ans.insert(arr[i]);
            }
        }

        vector<int> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};