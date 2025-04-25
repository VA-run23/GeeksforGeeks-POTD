/* 
    1. The function aims to find the majority element in the array arr, which appears more than n / 2 times. 
    2. It initializes a frequency array freq of size 10^6 to keep count of occurrences of each number in arr.
    3. The loop iterates over all elements in arr and updates the freq array for each value arr[i].
    4. After updating, it checks if the count for the current element exceeds n / 2. If yes, this element is returned.
    5. If no element meets the majority condition, the function returns -1 (although the problem guarantees a majority element exists).
    6. Time Complexity: The loop runs in O(n), where n is the size of arr. However, initializing the freq array is unnecessary for large inputs.
    7. Space Complexity: The freq array uses O(10^6) memory, which is excessive for sparse or small-value arrays.
*/

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int x = n/2;
        vector<int> freq(10e5, 0);
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
            if(freq[arr[i]] > x){
                return arr[i];
            }
        }
        return -1;
    }
};