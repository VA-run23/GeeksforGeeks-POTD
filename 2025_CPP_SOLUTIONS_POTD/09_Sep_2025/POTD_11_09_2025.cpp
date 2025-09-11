/*
    1. This function calculates the minimum number of jumps needed to reach the end of the array, where each element represents max jump length from that position.
    2. If the array has one or no elements, no jumps are needed; if the first element is 0, it's impossible to move forward.
    3. The loop iteratively selects the next position that offers the farthest reach within the current jump range.
    4. If the current position can directly reach or exceed the last index, the function returns the current jump count plus one.
    5. Within each jump range, it finds the position that maximizes the reach in the next step.
    6. If no progress can be made from the current position (i.e., nextPos == i), the function returns -1 indicating failure.
    7. Time Complexity: O(n), as each element is visited at most once; Space Complexity: O(1), using constant extra space.
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0; 
        if (arr[0] == 0) return -1; 

        int pos = 0, cnt = 0, last = n - 1;

        for (int i = 0; i < n;) {
            if (i + arr[i] >= last) return cnt + 1; 
            
            int maxReach = 0, nextPos = i;
            for (int j = i + 1; j <= min(i + arr[i], last); j++) {
                if (j + arr[j] > maxReach) {
                    maxReach = j + arr[j];
                    nextPos = j;
                }
            }

            if (nextPos == i) return -1; 

            i = nextPos;
            cnt++;
        }
        return -1; 
    }
};