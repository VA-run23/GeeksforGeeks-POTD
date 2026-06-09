// Seating Arrangement

/*
 *    1. We are given a row of seats represented as an array.
 *    2. Each seat can be empty (0) or already occupied (1).
 *    3. We need to check if we can seat 'k' additional people.
 *    4. No two people can sit adjacent to each other.
 *    5. First, mark seats adjacent to already occupied ones as unavailable (-1).
 *    6. Then, try to seat new people in remaining empty seats (0).
 *    7. Time Complexity: O(n), Space Complexity: O(1) — in-place marking.
 */

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
        for(int i=0;i<n;i++) {
            if (seats[i] == 1) {
                if (i > 0 && seats[i - 1] == 0) seats[i-1] = -1;
                if (i < n - 1 && seats[i + 1] == 0) seats[i+1] = -1;
            }
        }
        for(int i=0;i<n;i++) {
            if (k == 0) return true;
            if(seats[i] == 0) {
                k--;
                if(i > 0 && seats[i-1] == 0) seats[i-1] = -1;
                if(i < n - 1 && seats[i+1] == 0) seats[i+1] = -1;
            }
        }
        return k == 0;
    }
};

// Key Points
// 1. Seats marked as -1 are unavailable for seating.
// 2. Already occupied seats (1) block their neighbors.
// 3. Empty seats (0) can be filled if not adjacent to another person.
// 4. Greedy approach ensures maximum seating.
// 5. Early exit if all 'k' people are seated.
// 6. Works in-place without extra memory.
// 7. Efficient for large arrays due to linear scan.