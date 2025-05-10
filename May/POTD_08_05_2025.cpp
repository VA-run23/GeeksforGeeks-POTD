/*
    This function finds the missing number in an arithmetic progression.
    The common difference d is determined from the first and last two elements.
    Binary search is used to efficiently locate the missing number.
    At each step, mid is calculated and checked against expected values.
    If the progression holds, the search moves right; otherwise, it moves left.
    The missing number is derived using the initial term and calculated index.
    Time Complexity: O(log N), Space Complexity: O(1), where N is the array size.
*/
class Solution {
  public:
    int findMissing(vector<int> &arr) {
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
