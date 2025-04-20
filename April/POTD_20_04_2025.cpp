/*
    1. Determine the size of the array (n).
    2. Create a frequency vector initialized with zeros to track occurrences.
    3. Loop through each element in the array.
    4. If the frequency of the current number is already 1, it means it's a duplicate, so return it.
    5. Otherwise, increment the frequency count for the current number.
    6. The loop ensures we detect the duplicate number efficiently.
    7. Time Complexity: O(n) (since we iterate through the array once),
        Space Complexity: O(n) (due to the extra frequency array).
*/
  
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int n =arr.size();
        vector<int> freq(n, 0);
        for(int i =0; i< n; i++){
            if(freq[arr[i]] ==1)return arr[i];
            freq[arr[i]] ++;
        }
    }
};