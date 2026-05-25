// Elements in the Range

/*
 *    1. The problem requires checking if all elements in a given range exist in the array.
 *    2. We define the range using the provided start and end values.
 *    3. A helper vector is used to mark presence of elements within the range.
 *    4. Each element in the array is checked to see if it lies within the range.
 *    5. If it does, we mark its corresponding index in the presence vector.
 *    6. Finally, we verify if all positions in the presence vector are marked.
 *    7. Time Complexity: O(n), Space Complexity: O(end - start + 1)
 */

class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        vector<int>present(end - start + 1, 0);
        for(auto i: arr){
            if(i >= start && i <= end){
                present[i - start] = 1;
            }
        }
        for(auto i: present)if(i == 0)return false;
        return true;
    }
};

// Key Points
// 1. Uses a presence vector to track elements.
// 2. Efficiently maps array values to indices relative to the range.
// 3. Iterates through the array once for marking.
// 4. Iterates through the presence vector once for validation.
// 5. Handles ranges of any size within array constraints.
// 6. Returns false immediately if any element is missing.
// 7. Simple, clear, and optimal for this problem.