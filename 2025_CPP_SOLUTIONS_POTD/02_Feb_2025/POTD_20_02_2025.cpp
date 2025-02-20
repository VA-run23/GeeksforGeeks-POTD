class Solution {
public:
    priority_queue<int> pqmin; 
    priority_queue<int, vector<int>, greater<int>> pqmax; 
    vector<double> ans;

    void findMedian(int x, int i) {
        if (pqmax.empty() || x <= pqmax.top()) {
            pqmin.push(x);
        } else {
            pqmax.push(x);
        }

        if (pqmin.size() > pqmax.size() + 1) {
            pqmax.push(pqmin.top());
            pqmin.pop();
        } else if (pqmax.size() > pqmin.size()) {
            pqmin.push(pqmax.top());
            pqmax.pop();
        }

        if (pqmin.size() == pqmax.size()) {
            ans.push_back((pqmin.top() + pqmax.top()) / 2.0);
        } else {
            ans.push_back(pqmin.top());
        }
    }

    vector<double> getMedian(vector<int> &arr) {
        // code here
        for (int i = 0; i < arr.size(); i++) {
            findMedian(arr[i], i);
        }
        return ans;
    }
};