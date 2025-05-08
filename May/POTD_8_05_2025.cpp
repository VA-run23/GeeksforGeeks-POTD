/*
`
*/


class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int x = arr[1] - arr[0], 
            y = arr[n-1] - arr[n-2], 
            z = (arr[n-1] - arr[0]) / n;
        int d = (x==y || x==z) ? x : y;
        if (d == 0) return arr[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if ((arr[mid] - arr[0]) / d == mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return arr[0] + lo * d;
    }
};