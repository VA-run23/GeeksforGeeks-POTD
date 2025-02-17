class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        multiset<int> elems;
        for (int num : arr) {
            elems.insert(num);
            if (elems.size() > k) {
                elems.erase(elems.begin());
            }
        }

        vector<int> ans(elems.begin(), elems.end());
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};