/*
1. The function calculates the minimum jumps needed to reach the end of the array.
2. If the array has size 1, it returns 0, as no jumps are needed; if the first element is 0, it returns -1 (impossible to move).
3. Using a greedy approach, it tracks the current position (`pos`), the jump count (`cnt`), and the last index (`last`).
4. For each index, it checks if it can reach or surpass the last position; if yes, it returns the jump count incremented by 1.
5. Within the current jump range (`i` to `i + arr[i]`), it calculates the farthest reachable position (`maxReach`).
6. If no progress is possible (next position equals the current position), it returns -1 (unreachable).
7. The loop increments to the next optimal position (`nextPos`), and the jump count increases until the end is reached or proven impossible.
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