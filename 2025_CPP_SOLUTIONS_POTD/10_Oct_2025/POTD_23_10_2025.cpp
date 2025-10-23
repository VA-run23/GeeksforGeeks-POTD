/*
    1. This function finds the k closest points to the origin (0,0) using Euclidean distance.
    2. It uses a min-heap (priority_queue with greater comparator) to store pairs of (distance, index).
    3. For each point, it calculates the squared distance from the origin and pushes it into the heap.
    4. The heap ensures the smallest distances are at the top, allowing efficient retrieval.
    5. It then pops the top k elements from the heap and uses their indices to collect the original points.
    6. The result is stored in a vector of vectors and returned.
    7. Time Complexity: O(n log n) for heap insertion; O(k log n) for extracting k elements. Space Complexity: O(n) for the heap.
*/

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<float, int>, vector<pair<float, int>> , greater<pair<float, int>>> pq;
        int n = points.size();
        for(int i = 0; i<n; i++){
            float dist = (pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({dist, i});
        }
        
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};