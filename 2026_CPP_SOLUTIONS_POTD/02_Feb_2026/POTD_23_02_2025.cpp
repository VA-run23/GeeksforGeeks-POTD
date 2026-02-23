/*
1. This function computes the union of two integer arrays a and b.
2. A    set<int>' is used to store elements uniquely and in sorted order.
3. The constructor initializes the set with all elements of array a.
4. Elements of array b are then inserted, ensuring duplicates are removed.
5. The set is converted into a vector 'ans', which contains the sorted union.
6. Time Complexity: O((n + m) * log(n + m)) due to balanced tree insertions.
7. Space Complexity: O(n + m) for storing the union in the set and result vector.
*/

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>s(a.begin(), a.end());
        s.insert(b.begin(), b.end());
        vector<int> ans(s.begin(), s.end());
            
        return ans;
    }
};

// Key points:
// - Using 'set' ensures uniqueness and sorted order automatically.
// - This avoids the need for an extra sorting step after union creation.
// - If arrays are already sorted, a two-pointer merge approach is more optimal.
// - Two-pointer method runs in O(n + m) time with O(1) extra space.
// - Reserving vector capacity can reduce reallocation overhead in large cases.
// - Choice of method depends on whether sorted output is required and input order.
