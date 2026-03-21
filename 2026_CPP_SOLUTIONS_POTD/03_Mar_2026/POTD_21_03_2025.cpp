// Number of BST From Array

/*
 *    1. We are given an array of integers.
 *    2. For each element, we count how many are smaller and how many are greater.
 *    3. Using precomputed Catalan numbers, we calculate possible BSTs.
 *    4. The number of BSTs for each element is product of left-subtree and right-subtree counts.
 *    5. Catalan numbers are stored in a vector for quick lookup.
 *    6. We iterate through the array and compute results for each element.
 *    7. Time Complexity: O(n^2), Space Complexity: O(n)
 */

class Solution {
  public:
    vector<int> bsts = {1, 1, 2, 5, 14, 42 };
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
    
        int n=arr.size();
        vector<int> bstCount;
        for(int i = 0; i<n; i++){
            int l=0, g=0;
            for(int j = 0;j<n;j++){
                if(arr[i]<arr[j]){
                    g++;
                }
                else if(arr[i]>arr[j]){
                    l++;
                }
            }
            bstCount.push_back(bsts[l]*bsts[g]);
        }
        return bstCount;
    }
};

// Key Points
// 1. Catalan numbers are used to count BSTs.
// 2. Each element is treated as root.
// 3. Left count = elements smaller than root.
// 4. Right count = elements greater than root.
// 5. Result = product of left and right subtree possibilities.
// 6. Precomputed Catalan numbers speed up calculation.
// 7. Brute force approach is O(n^2).