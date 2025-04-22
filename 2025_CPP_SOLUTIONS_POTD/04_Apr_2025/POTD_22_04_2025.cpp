/* 
    This function finds the unique element in an array where every element appears twice except one. 
    It initializes x to 0 and iterates through the array, applying the XOR operator. 
    XOR eliminates duplicate elements since A ^ A = 0 and retains the unique number (A ^ 0 = A). 
    As a result, all duplicate numbers cancel out, leaving only the unique number in x. 
    The time complexity is O(N) since we iterate through the entire array once. 
    The space complexity is O(1), as only a single integer variable x is used for computation. 
    This approach is efficient and widely used for single-number problems. 
*/

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int x =0, n = arr.size();
        for(int i =0; i<n; i++ ){
            x = x ^ arr[i];
        }
        return x;
    }
};