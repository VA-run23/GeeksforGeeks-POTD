/*
    1. This solution uses the Merge Sort algorithm to count inversions efficiently.
    2. We divide the array into halves recursively until single elements remain.
    3. During the merge step, we compare elements from left and right subarrays.
    4. If an element in the right subarray is smaller than the left, it implies inversions.
    5. The count is incremented by (mid - leftIdx + 1) for each such occurrence.
    6. Time Complexity: O(N log N) due to the divide and conquer approach.
    7. Space Complexity: O(N) required for the temporary vector during merging.
*/
class Solution {
  private:
    long long merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> tempArr;
        int leftIdx = left;
        int rightIdx = mid + 1;
        long long invCount = 0;

        while (leftIdx <= mid && rightIdx <= right) {
            if (arr[leftIdx] <= arr[rightIdx]) {
                tempArr.push_back(arr[leftIdx]);
                leftIdx++;
            } else {
                tempArr.push_back(arr[rightIdx]);
                invCount += (mid - leftIdx + 1);
                rightIdx++;
            }
        }
        while (leftIdx <= mid) {
            tempArr.push_back(arr[leftIdx]);
            leftIdx++;
        }
        while (rightIdx <= right) {
            tempArr.push_back(arr[rightIdx]);
            rightIdx++;
        }
        for (int i = 0; i < tempArr.size(); i++) {
            arr[left + i] = tempArr[i];
        }
        return invCount;
    }

    long long mergeSort(vector<int> &arr, int left, int right) {
        long long count = 0;
        if (left >= right) return count;
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
        return count;
    }

  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        return (int)mergeSort(arr, 0, arr.size() - 1);
    }
};

/*
Key points:
- The problem requires finding pairs where i < j but arr[i] > arr[j].
- A brute force O(N^2) approach fails on large inputs (10^5).
- Merge Sort is modified to count "jumps" whenever an element from the right half moves before the left half.
- Using `long long` for the counter is critical to prevent overflow.
*/