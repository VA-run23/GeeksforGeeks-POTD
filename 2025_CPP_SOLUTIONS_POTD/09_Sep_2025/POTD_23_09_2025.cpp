/*
    1. This function reverses a queue using recursion without using any extra data structures.
    2. Base case: If the queue is empty, the function returns immediately.
    3. It stores the front element of the queue in variable 'x' and removes it.
    4. Then it recursively calls reverseQueue on the remaining queue.
    5. After the recursive call, it pushes 'x' back to the rear of the queue.
    6. This process continues until all elements are reinserted in reverse order.
    7. Time Complexity: O(n), Space Complexity: O(n) due to recursive call stack.
*/

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.empty()){
            return ;
        }
        int x=q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
};