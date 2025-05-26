/* 
   1. If the list is empty, create a new circular node with the given data.
   2. Create a new node to insert and initialize traversal pointers.
   3. If the new data is smaller than the head node's data, update the last node's next pointer and insert at the beginning.
   4. Traverse the list to find the correct position for insertion while maintaining sorted order.
   5. Update next pointers to insert the new node between 'prev' and 'temp'.
   6. Ensure the circular linked list structure remains intact after insertion.
   7. Return the updated head of the circular linked list.
*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        if (head == NULL) {
            head = new Node(data);
            head->next = head;
            return head;
        }

        Node *toInsert = new Node(data);
        Node *prev = head;
        Node *temp = head->next;

        if (data < head->data) {
            while (temp->next != head) temp = temp->next;
            toInsert->next = head;
            temp->next = toInsert;
            return toInsert;
        }

        while (temp != head && temp->data < data) {
            prev = temp;
            temp = temp->next;
        }

        toInsert->next = temp;
        prev->next = toInsert;

        return head;
    }
};
