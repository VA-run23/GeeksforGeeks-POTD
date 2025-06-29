/*
    1. The function counts, for each element in array 'a', how many elements in array 'b' are less than or equal to it.
    2. First, array 'b' is sorted to enable binary search operations with upper_bound.
    3. A result vector 'ans' is initialized to store the counts.
    4. For every element 'x' in 'a', upper_bound is used on sorted 'b' to find the index of the first element greater than 'x'.
    5. The number of elements less than or equal to 'x' in 'b' is the index returned by upper_bound.
    6. This count is pushed into the result vector 'ans' for each element in 'a'.
    7. Finally, 'ans' is returned as the result.

    Time Complexity: O(M log M + N log M), where M = size of b, N = size of a.
    Space Complexity: O(1) auxiliary (excluding output vector).
*/

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        
        vector<int> ans;
        for(int x : a) {
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            ans.push_back(count);
        }
        
        return ans;
    }
};