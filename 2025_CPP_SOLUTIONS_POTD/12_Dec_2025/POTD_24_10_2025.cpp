/*
    1. The function takes a rotated sorted array and a value x, and counts elements <= x.
    2. First, it finds the pivot (smallest element index) using binary search on arr[low..high].
    3. The pivot splits the rotated array into two sorted halves: [0..pivot-1] and [pivot..n-1].
    4. In each half, we use upper_bound to find the position of the first element > x.
    5. Subtracting iterators gives the count of elements <= x in that half (no need for casting).
    6. We sum counts from both halves to get the total number of elements <= x.
    7. Time Complexity: O(log n) for pivot + O(log n) for each upper_bound → O(log n) overall; Space Complexity: O(1).
*/

class Solution {
  public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high]) low = mid + 1;
            else high = mid;
        }
        int pivot = low;
        int count = 0;
        count += upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();
        count += upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);
    
        return count;
    }
};