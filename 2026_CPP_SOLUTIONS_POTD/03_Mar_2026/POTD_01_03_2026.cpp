/*
    1. This function moves all zeros in the array to the end while keeping non-zero elements in order.
    2. It uses a variable 'x' to track the position where the next non-zero element should be placed.
    3. The first loop iterates through the array, copying non-zero elements to the front.
    4. Each time a non-zero element is found, it is placed at index 'x', and 'x' is incremented.
    5. After the first loop, all non-zero elements are compacted at the beginning of the array.
    6. The second loop fills the remaining positions (from 'x' to end) with zeros.
    7. Time Complexity: O(n), Space Complexity: O(1).
*/
class Solution {~
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int x = 0, n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] > 0){
                arr[x++] = arr[i];
            }
        }
        for(int i = x; i<n; i++){
            arr[i] =0;
        }
    }
};

// Key points:
// - The algorithm uses two passes: one to shift non-zero elements forward, one to insert zeros.
// - It maintains the relative order of non-zero elements (stable).
// - Efficient because it runs in linear time and constant space.
// - The variable 'x' acts as a pointer to the next available slot for non-zero values.
// - After compaction, trailing positions are filled with zeros.
