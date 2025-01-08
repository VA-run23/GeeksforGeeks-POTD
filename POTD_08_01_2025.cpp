class Solution {
public:

    int countTriangles(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int tri = 0;
        int n = arr.size();
        
        
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                
                if (arr[left] + arr[right] > arr[i]) {
                    tri += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return tri;
    }
};
