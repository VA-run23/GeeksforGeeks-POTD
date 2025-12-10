/*
1. The function takes an array of size n containing numbers from 1 to n, with one missing and one repeating.
2. It iterates through the array, using the absolute value of each element to map to an index (value - 1).
3. If the element at that index is already negative, it means the current value has been seen before → repeating number found.
4. Otherwise, it marks the element at that index as visited by negating it.
5. After the first loop, it iterates again to find the missing number: the index whose value is still positive corresponds to the missing number.
6. The repeating number and missing number are stored in the result vector `ans`.
7. Finally, the function returns the vector containing [repeating, missing].
Time Complexity: O(n) (single pass + second pass).
Space Complexity: O(1) (ignores output vector, modifies array in-place).
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;  
            if(arr[idx] < 0) {
                ans.push_back(idx + 1); 
            } else {
                arr[idx] = -arr[idx];
            }
        }

        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                ans.push_back(i + 1); 
                break;
            }
        }

        return ans;
    }
};
