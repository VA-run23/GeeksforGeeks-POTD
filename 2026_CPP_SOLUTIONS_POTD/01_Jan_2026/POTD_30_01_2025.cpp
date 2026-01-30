/*
    1. This function rearranges a queue of integers such that elements from the first half and second half are interleaved.  
    2. It first transfers all elements from the queue into a temporary vector for easier access.  
    3. Each pair (firstHalf, secondHalf) is combined into a single long using bit manipulation (shifting and OR).  
    4. The left shift by 20 ensures enough space to store both integers without overlap.  
    5. Later, the combined value is split back into its original two integers using right shift and bit masking.  
    6. These split values are then pushed back into the queue in the desired interleaved order.  
    7. Time Complexity: O(n), Space Complexity: O(n) due to the temporary vector.  
*/

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        vector<long> temp;

        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }

        for (int i = 0; i < n/2; i++) {
            long firstHalf = temp[i];
            long secondHalf = temp[i + n/2];

            temp[i] = (firstHalf << 20) | secondHalf;
        }

        for (int i = 0; i < n/2; i++) {
            long combined = temp[i];
            int firstHalf = combined >> 20;              
            int secondHalf = combined & ((1 << 20) - 1);   

            q.push(firstHalf);
            q.push(secondHalf);
        }
    }
};

// Key points:
// - The queue is split into two halves and then interleaved.
// - Bit manipulation is used to temporarily store pairs in one number.
// - Shifting ensures separation of values, masking retrieves the second half.
// - This avoids using two separate arrays for halves.
// - Complexity remains O(n) time and O(n) space.
// - The approach is clever but slightly over-engineered for simple interleaving.
// - Simpler methods exist using auxiliary queues or stacks without bit tricks.
