/*
    1. This function segregates a linked list into three parts: nodes with values 0, 1, and 2.
    2. Temporary linked lists (zeros, ones, twos) are created to collect nodes based on their values.
    3. A traversal is performed through the original list, linking nodes to the respective temporary list.
    4. At the end of the traversal, the lists are merged: zeros followed by ones, then twos.
    5. Temporary heads (zeros, ones, twos) are deleted to free memory.
    6. The new head of the combined list (newHead) is returned as the result.
    7. Time Complexity: O(n), where n is the number of nodes, as we traverse the list once. 
    Space Complexity: O(1), as no extra data structures are used besides pointers.
*/

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        
        if (!head) return head;

        Node* zeros = new Node(0);
        Node* ones = new Node(0);
        Node* twos = new Node(0);

        Node *zero = zeros, *one = ones, *two = twos;
        Node* curr = head;

        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = (ones->next) ? ones->next : twos->next;
        one->next = twos->next;
        two->next = nullptr;

        Node* newHead = zeros->next;

        delete zeros;
        delete ones;
        delete twos;

        return newHead;
    }
};