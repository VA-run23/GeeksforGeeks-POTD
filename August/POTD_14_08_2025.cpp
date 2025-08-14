/*
    1. This solution uses a modified merge sort to count reverse pairs where arr[i] > 2 * arr[j] and i < j.
    2. The array is recursively divided, and reverse pairs are counted during the merge step.
    3. For each element in the left half, it counts how many elements in the right half satisfy the condition.
    4. The merge step also sorts the array to maintain order for efficient counting.
    5. The use of 2LL ensures safe multiplication without integer overflow.
    6. Time Complexity: O(n log n) due to divide-and-conquer and binary search during merge.
    7. Space Complexity: O(n) for the temporary vector used during merging.
*/

class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        return mergeSort(arr, 0, arr.size() - 1);
    }

private:
    int mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right);

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && arr[i] > 2LL * arr[j]) j++;
            count += j - (mid + 1);
        }

        vector<int> temp;
        int i = left, k = mid + 1;
        while (i <= mid && k <= right)
            temp.push_back(arr[i] <= arr[k] ? arr[i++] : arr[k++]);
        while (i <= mid) temp.push_back(arr[i++]);
        while (k <= right) temp.push_back(arr[k++]);
        for (int i = left; i <= right; i++) arr[i] = temp[i - left];

        return count;
    }
};
