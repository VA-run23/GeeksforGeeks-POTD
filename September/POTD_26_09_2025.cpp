/*
    1. This function rotates a deque either to the right (type 1) or to the left (type 2) by k positions.
    2. It first checks if the deque is empty; if so, it returns immediately as there's nothing to rotate.
    3. Then it reduces k modulo n to avoid unnecessary full rotations, since rotating n times results in the same deque.
    4. If k becomes 0 after modulo, it returns early as no rotation is needed.
    5. For type 1 (right rotation), it moves the last k elements to the front using std::rotate.
    6. For type 2 (left rotation), it moves the first k elements to the back using std::rotate.
    7. Time Complexity: O(n), Space Complexity: O(1) — std::rotate performs in linear time with constant space.
*/

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n = dq.size();
        if (n == 0) return;

        k %= n; 
        if (k == 0) return;

        if (type == 1) {
            rotate(dq.begin(), dq.end() - k, dq.end());
        } 
        else if (type == 2) {
            rotate(dq.begin(), dq.begin() + k, dq.end());
        }
    }
};