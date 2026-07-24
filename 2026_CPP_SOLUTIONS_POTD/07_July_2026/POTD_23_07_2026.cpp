// Check Preorder of BST

/*
 *    1. The problem asks whether a given array can represent
 *       the preorder traversal of a Binary Search Tree (BST).
 *    2. Use a stack to simulate BST construction.
 *    3. Maintain a variable `limit` to track the smallest allowed value
 *       (ensuring BST property for right subtrees).
 *    4. Traverse the array:
 *       - If current value < limit → invalid preorder.
 *       - While stack top < current value → pop and update limit.
 *       - Push current value onto stack.
 *    5. If traversal completes without violation, return true.
 *    6. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int limit = INT_MIN;
        
        for (int &x : arr) {
            // If value is less than allowed limit, invalid BST preorder
            if (x < limit) return false;
            
            // Pop smaller values and update limit
            while (!st.empty() && x > st.top()) {
                limit = st.top();
                st.pop();
            }
            
            // Push current value
            st.push(x);
        }
        
        return true;
    }
};

// Key Points
// 1. Preorder traversal must respect BST rules.
// 2. Stack simulates traversal and subtree boundaries.
// 3. `limit` ensures values in right subtree are greater than ancestors.
// 4. Any violation (x < limit) means invalid preorder.
// 5. Efficient O(n) solution with linear scan and stack.