class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res(n, 0);
        int x = 1;
        int zCnt = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                x *= arr[i];
            } else {
                zCnt++;
            }
        }

            if (zCnt > 1) {
            return res;
        }

        if (zCnt == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    res[i] = x;
                }
            }
            return res;
        }

        for (int i = 0; i < n; i++) {
            res[i] = x / arr[i];
        }

        return res;
    }
};