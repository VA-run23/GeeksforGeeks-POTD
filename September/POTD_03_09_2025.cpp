/*
    1. This function reverses a doubly linked list by swapping the 'next' and 'prev' pointers of each node.
    2. It starts with the head node and iterates through the list using a pointer 'curr'.
    3. For each node, it temporarily stores the 'prev' pointer in 'temp'.
    4. Then it swaps the 'prev' and 'next' pointers of the current node.
    5. The head is updated to the current node during each iteration to eventually point to the new head.
    6. The loop continues by moving to the original 'next' node, now accessible via 'prev' after the swap.
    7. Time Complexity: O(n), Space Complexity: O(1) — where n is the number of nodes in the list.
*/

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            head = curr;
            curr = curr->prev;
        }

        return head;
    }
};