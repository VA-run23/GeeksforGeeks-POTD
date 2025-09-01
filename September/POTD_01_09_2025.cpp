/*
    1. This function computes the sum of modes for all subarrays of size k in the input array 'arr'.
    2. It uses a sliding window approach with two pointers 'i' and 'j' to iterate over all subarrays of size k.
    3. A frequency map 'freq' tracks the count of each element, while a set 'ss' maintains elements ordered by frequency and value.
    4. The set stores pairs '{n - freq[val], val}' so that higher frequency elements appear earlier (since set is sorted in ascending order).
    5. For each window, the mode is the element with the highest frequency and smallest value, found at '(*ss.begin()).second'.
    6. The mode of each window is added to 'modeSum', and the window is updated by removing the outgoing element and adding the incoming one.
    7. Time complexity is O(n log k) due to set operations per window, and space complexity is O(k) for storing frequencies and set elements.
*/

class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        set<pair<int, int>> ss;
        int modeSum = 0;

        int i = 0, j = 0;
        while (j - i != k) {
            int val = arr[j];
            pair<int, int> p = {n - freq[val], val};
            if (ss.find(p) != ss.end()) {
                ss.erase(p);
            }
            freq[val]++;
            p = {n - freq[val], val};
            ss.insert(p);
            j++;
        }

        modeSum += (*ss.begin()).second;

        while (j < n) {
            int val = arr[i];
            pair<int, int> p = {n - freq[val], val};
            if (ss.find(p) != ss.end()) {
                ss.erase(p);
            }
            freq[val]--;
            p = {n - freq[val], val};
            ss.insert(p);

            val = arr[j];
            p = {n - freq[val], val};
            if (ss.find(p) != ss.end()) {
                ss.erase(p);
            }
            freq[val]++;
            p = {n - freq[val], val};
            ss.insert(p);

            modeSum += (*ss.begin()).second;
            i++;
            j++;
        }
        return modeSum;
    }
};