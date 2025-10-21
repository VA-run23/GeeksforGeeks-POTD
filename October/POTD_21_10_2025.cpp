/*
    1. The function 'topKFreq' finds the top 'k' most frequent elements in the input array 'arr', prioritizing larger numbers when frequencies match.
    2. It initializes a frequency vector 'freq' of size 1e5+7 to store pairs of (element, frequency), assuming element values range from 1 to 1e5.
    3. It iterates through 'arr', updating the frequency count for each element in 'freq'.
    4. It filters out elements with zero frequency into a new vector 'filtered'.
    5. The 'filtered' vector is sorted by frequency in descending order; if frequencies tie, the larger number comes first.
    6. The top 'k' elements from the sorted 'filtered' list are pushed into the result vector 'ans'.
    7. Time Complexity: O(n + m log m), where n = arr.size() and m = number of distinct elements; Space Complexity: O(1e5) for frequency tracking.
*/

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        vector<pair<int, int>> freq(1e5 + 7, {0, 0});
            
        for (int num : arr) {
            freq[num].first = num;
            freq[num].second++;
        }

        vector<pair<int, int>> filtered;
        for (auto& p : freq) {
            if (p.second > 0) {
                filtered.push_back(p);
            }
        }
        sort(filtered.begin(), filtered.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second)
                return a.first > b.first; 
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k && i < filtered.size(); i++) {
            ans.push_back(filtered[i].first);
        }
        
        return ans;
    }
};