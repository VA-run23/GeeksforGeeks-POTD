class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        int n = points.size();
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>>> maxHeap;

        for (int i = 0; i < n; i++) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            maxHeap.push({dist, points[i]});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};