// Max Amount by Selling K Tickets

/*
 *    1. Each ticket seller has a certain number of tickets represented in the array.
 *    2. At each step, sell one ticket from the seller with the maximum tickets left.
 *    3. Use a max-heap (priority queue) to efficiently retrieve the seller with the most tickets.
 *    4. After selling, decrease the seller’s ticket count and push it back if still positive.
 *    5. Accumulate the ticket values sold into the answer.
 *    6. Apply modulo 1e9+7 to handle large sums and prevent overflow.
 *    7. Time Complexity: O(k log n), Space Complexity: O(n).
 */

class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int>q(arr.begin(), arr.end());
        int ans = 0, mod = 1e9+7;
        while(k && !q.empty()){
            int top = q.top();
            q.pop();
            if(top > 1) q.push(top - 1);
            ans = (ans + top) % mod;
            k--;
        }
        return ans % mod;
    }
};

// Key Points
// 1. Priority queue ensures efficient retrieval of maximum tickets.
// 2. Always sell from the seller with the highest remaining tickets.
// 3. Push back decremented ticket count to maintain heap property.
// 4. Stop when k tickets are sold or heap becomes empty.
// 5. Modulo operation prevents integer overflow.
// 6. Handles large inputs efficiently with logarithmic operations.
// 7. Optimal greedy approach using heap data structure.