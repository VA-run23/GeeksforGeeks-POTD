/*
    1. The function 'mergeCount' is a modified merge sort that merges two sorted halves while counting inversions (cases where left element > right element).
    2. During merging, if 'b[j] < b[i]', then since the left half is sorted, all remaining elements from 'i' to 'mid' are greater than 'b[j]', so '(mid - i + 1)' inversions are added.
    3. A temporary vector 'temp' is used to store merged elements in sorted order, which are copied back into the original array segment after merging.
    4. In 'countPairs', the array 'arr' is transformed into 'b[i] = i * arr[i]', encoding the condition '(i * arr[i] > j * arr[j])' into a standard inversion problem.
    5. The recursion ensures that at the base case single elements are trivially sorted, and as blocks are merged upward, inversions are counted across left and right halves.
    6. The total inversion count across all merge steps gives the final answer, since inversions in 'b' directly represent valid pairs in the original array.
    7. Time Complexity: O(n log n) due to merge sort recursion and merging; Space Complexity: O(n) for temporary storage during merging.
*/

// Key Points :
// - Guarantee of '(mid - i + 1)': Works because each half is sorted before merging, so if 'b[j] < b[i]', then 'b[j]' is smaller than all remaining left-half elements.
// - Sorting blocks recursively: Base case is single elements; merging builds larger sorted blocks while counting inversions.
// - Transformation step: Multiplying index with value ('i * arr[i]') converts the special condition into a standard inversion problem.
// - Why inversion counting solves it: Once transformed, the problem reduces to counting inversions in 'b', which merge sort handles efficiently.
// - Accumulation: Inversions are counted at every merge step and summed up to give the final answer.

class Solution {
  public:
    int mergeCount(vector<int>& b, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int inv = 0;
        inv += mergeCount(b, left, mid);
        inv += mergeCount(b, mid + 1, right);

        vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (b[i] <= b[j]) {
                temp.push_back(b[i++]);
            } else {
                temp.push_back(b[j++]);
                inv += (mid - i + 1); 
            }
        }
        while (i <= mid) temp.push_back(b[i++]);
        while (j <= right) temp.push_back(b[j++]);

        for (int k = left; k <= right; k++) {
            b[k] = temp[k - left];
        }
        return inv;
    }

    int countPairs(int arr[], int n) {
        // Your code goes here
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = i * arr[i]; 
        }
        return mergeCount(b, 0, n - 1);
    }
};