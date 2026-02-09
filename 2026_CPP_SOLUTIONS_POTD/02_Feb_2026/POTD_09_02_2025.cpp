/*
    1. This function finds the index of rotation in a rotated sorted array.
    2. It iterates through the array to detect the point where order breaks.
    3. Specifically, it checks where arr[i] > arr[i+1], meaning rotation occurs.
    4. The index after this break (i+1) is returned as the rotation count.
    5. If no break is found, the array is already sorted, so return 0.
    6. Time Complexity: O(n), since it scans the array once.
    7. Space Complexity: O(1), as no extra data structures are used.
*/
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size() - 1;
        for(int i= 0; i<n ; i++){
            if(arr[i] >  arr[i+1]) return i +1;
        }
        return 0;
    }
};

// Key points:
// - The code finds the rotation count by detecting the first drop in sorted order.
// - It returns the index where the rotation occurs.
// - If no drop is found, the array is not rotated.
// - Linear scan makes it simple but not optimal.
// - Time complexity is O(n), space complexity is O(1).