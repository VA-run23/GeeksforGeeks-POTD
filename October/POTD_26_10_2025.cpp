/*
    1. Initialize a min-heap (priority queue) with all rope lengths to always access the shortest ropes first.
    2. If there's only one rope, return 0 since no connections are needed.
    3. While more than one rope remains, extract the two shortest ropes from the heap.
    4. Add their lengths to compute the cost of connecting them and push the new rope back into the heap.
    5. Accumulate the total cost after each connection and reduce the rope count.
    6. Repeat until only one rope remains in the heap, which represents the final connected rope.
    7. Time Complexity: O(n log n), Space Complexity: O(n) — due to heap operations and storage.
*/

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        int cost = 0;
        priority_queue<int, vector<int> , greater<int>>pq(arr.begin(), arr.end());
        
        while(n !=1){
            int first = pq.top();
            pq.pop();
            // if(pq.empty()) return cost;
            int second = pq.top();
            int sum = first + second;
            pq.pop();
            pq.push(sum);
            cost += sum;
            n--;    
        }
        return cost;
    }
};