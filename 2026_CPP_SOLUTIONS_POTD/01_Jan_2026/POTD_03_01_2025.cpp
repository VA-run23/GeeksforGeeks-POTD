/*
    1. The function 'merge' takes two sorted linked lists (connected via bottom pointers) and merges them into one sorted list.  
    2. If either list is null, it simply returns the other list, ensuring base cases are handled.  
    3. It compares the data of the current nodes and recursively attaches the smaller node’s bottom pointer to the merged result.  
    4. The 'next' pointer of the merged nodes is set to null because only bottom pointers are used in the flattened list.  
    5. The 'flatten' function recursively flattens the list starting from the rightmost sublist (root->next) and then merges it with the current list.  
    6. This recursive approach ensures that all lists are merged into one sorted linked list using bottom pointers only.  
    7. Time Comple'xity: O(N * M) in worst case (N = number of nodes in main list, M = average length of bottom lists); Space Complexity: O(1) auxiliary space (excluding recursion stack).  
*/

class Solution {
  public:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        result->next = nullptr;
        return result;
    }
    Node *flatten(Node *root) {
        // code here
        if (!root || !root->next) return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};