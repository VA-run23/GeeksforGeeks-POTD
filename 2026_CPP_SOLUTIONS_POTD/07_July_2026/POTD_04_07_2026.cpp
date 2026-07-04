// Count the Substring

/*
 *    1. The problem is to count substrings with more 1's than 0's.
 *    2. We use prefix sums where '1' contributes +1 and '0' contributes -1.
 *    3. The task reduces to counting pairs (i, j) with prefix[j] > prefix[i].
 *    4. This is efficiently solved using a modified merge sort approach.
 *    5. During merging, we count valid pairs across left and right halves.
 *    6. The merge step also sorts the prefix array for correct counting.
 *    7. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
    public:
    long long ans = 0;
    
    void merge(vector<int>& a, int l, int mid, int r) {
        
        int i = l;
        for (int j = mid + 1; j <= r; j++) {
            while (i <= mid && a[i] < a[j])
                i++;
            
            ans += (i - l);
        }
        
        vector<int> temp;
        int left = l;
        int right = mid + 1;
        
        while (left <= mid && right <= r) {
            if (a[left] <= a[right])
                temp.push_back(a[left++]);
            else
                temp.push_back(a[right++]);
        }
        
        while (left <= mid)
            temp.push_back(a[left++]);
        
        while (right <= r)
            temp.push_back(a[right++]);
        
        for (int k = l; k <= r; k++)
            a[k] = temp[k - l];
    }
    
    void mergeSort(vector<int>& a, int l, int r) {
        if (l >= r)
            return;
        
        int mid = l + (r - l) / 2;
        
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        
        merge(a, l, mid, r);
    }
    int countSubstring(string& s) {
        // Code Here
        int n = s.size();
        
        vector<int> prefix(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }
        
        ans = 0;
        mergeSort(prefix, 0, n);
        
        return ans;
    }
};

// Key Points
// 1. Prefix sums transform the substring problem into a pair-counting problem.
// 2. Merge sort is used to count pairs efficiently.
// 3. The counting happens during the merge step.
// 4. Sorting ensures correctness for subsequent merges.
// 5. The algorithm avoids brute force O(n^2) checking.
// 6. Works for large strings due to O(n log n) complexity.
// 7. Space complexity is linear due to prefix and temporary arrays.