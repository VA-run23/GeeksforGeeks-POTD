/*
   1. The function 'searchInsertK' takes a sorted vector 'arr' and an integer 'k' as input.
   2. It uses the STL function 'lower_bound' to find the first position where 'k' can be inserted.
   3. 'lower_bound(arr.begin(), arr.end(), k)' returns an iterator pointing to the position of 'k' if found, 
      or the position where 'k' should be inserted to maintain sorted order.
   4. Subtracting 'arr.begin()' from this iterator gives the index (0-based) of that position.
   5. If 'k' exists in the array, the index returned is its actual position.
   6. If 'k' does not exist, the index returned is the correct insertion point to keep the array sorted.
   7. Time Complexity: O(log n) due to binary search in 'lower_bound'; Space Complexity: O(1) as no extra space is used.
*/

// Key Points:
// - 'lower_bound' is a binary search-based STL function.
// - It ensures both search and insertion index are handled in one line.
// - Efficient solution compared to linear search (O(n)).
// - Works only on sorted arrays.
// - Returns index directly by subtracting iterator from 'arr.begin()'.
// - Handles both "element found" and "element not found" cases seamlessly.

class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    }
};