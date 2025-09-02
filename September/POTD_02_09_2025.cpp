/*
    1. Count the number of nodes (n) in the linked list to determine the positions of the kth nodes from start and end.
    2. If k is greater than n or the kth node from start and end are the same, return the original list.
    3. Traverse to the kth node from the beginning (node1) and keep track of its previous node (prev1).
    4. Traverse to the kth node from the end (node2) and keep track of its previous node (prev2).
    5. Update the previous nodes' next pointers to point to the opposite kth nodes, handling head updates if needed.
    6. Swap the next pointers of node1 and node2 to complete the node swap.
    7. Return the updated head of the linked list.

    Time Complexity: O(n) — due to traversing the list multiple times.
    Space Complexity: O(1) — no extra space used beyond pointers.
*/


class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        if (k > n || 2 * k - 1 == n) return head;

        Node* prev1 = nullptr, *node1 = head;
        for (int i = 1; i < k; i++) {
            prev1 = node1;
            node1 = node1->next;
        }

        Node* prev2 = nullptr, *node2 = head;
        for (int i = 1; i < n - k + 1; i++) {
            prev2 = node2;
            node2 = node2->next;
        }

        if (prev1) prev1->next = node2;
        else head = node2;

        if (prev2) prev2->next = node1;
        else head = node1;

        Node* tempNext = node1->next;
        node1->next = node2->next;
        node2->next = tempNext;

        return head;
    }
};