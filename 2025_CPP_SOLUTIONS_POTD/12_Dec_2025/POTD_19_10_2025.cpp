/*
   1. The function 'findMoves' takes two arrays: 'chairs' (positions of chairs) and 'passengers' (positions of passengers).
   2. Both arrays are sorted so that we can optimally match each passenger to the nearest available chair in order.
   3. Sorting ensures that the smallest passenger position is matched with the smallest chair position, minimizing total moves.
   4. After sorting, we iterate through all passengers and chairs simultaneously.
   5. For each index 'i', we calculate the absolute difference between 'chairs[i]' and 'passengers[i]' (moves needed).
   6. These differences are accumulated in 'ans', which represents the total minimum moves required.
   7. Finally, the function returns 'ans'. 
      Time Complexity: O(n log n) due to sorting. 
      Space Complexity: O(1) (ignoring input storage, only constant extra space used).
*/

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        int n = chairs.size(), i = 0;
        int ans = 0;
        for(i = 0; i<n; i++){
            ans += abs(chairs[i] - passengers[i]);
        }
        return ans;
    }
};