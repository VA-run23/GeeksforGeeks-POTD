/*
   1. The function 'kthElement' takes two sorted arrays 'a' and 'b' and an integer 'k', 
      and aims to find the k-th element in the merged sorted order of both arrays.  

   2. Variables 'n' and 'm' store the sizes of arrays 'a' and 'b', while 'i' and 'j' 
      are pointers used to traverse the arrays sequentially.  

   3. The variable 'ans' is initialized to -1 and will eventually hold the k-th element 
      after merging logic is applied.  

   4. A loop runs until 'k' becomes zero, simulating the process of merging arrays 
      element by element in sorted order.  

   5. Inside the loop, if the current element of 'a' is smaller (or if 'b' is exhausted), 
      'ans' is updated with 'a[i]' and 'i' is incremented; otherwise, 'ans' is updated 
         with 'b[j]' and 'j' is incremented.  

      6. Each iteration reduces 'k' by one, ensuring that after exactly 'k' picks, 
         'ans' holds the k-th smallest element in the merged sequence.  

      7. Finally, the function returns 'ans', which is the required k-th element.  
         Time Complexity: O(k) (since we simulate merging until k steps).  
         Space Complexity: O(1) (no extra space used apart from variables).  
*/

// Key Points:
// - This approach is essentially a partial merge of two sorted arrays.
// - Efficient for small k, but for very large arrays and k, binary search based methods 
//   can achieve O(log(min(n, m))) complexity.
// - Works correctly even if one array is exhausted before reaching k.
// - Simple and intuitive, but not optimal for huge datasets.

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        int ans = -1;
        while (k > 0) {
            if (i < n && (j >= m || a[i] <= b[j])) {
                ans = a[i];
                i++;
            } else {
                ans = b[j];
                j++;
            }
            k--;
        }
        return ans;
    }
};