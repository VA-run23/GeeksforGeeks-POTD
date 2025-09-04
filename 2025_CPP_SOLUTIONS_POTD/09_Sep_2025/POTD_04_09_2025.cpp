/*
    1. This function reverses nodes of a singly linked list in groups of size k using iterative pointer manipulation.
    2. It traverses the list, reversing k nodes at a time by reassigning their next pointers in a loop.
    3. If fewer than k nodes remain at the end, they are left as-is and linked back to the reversed portion.
    4. The variable 'newHead' stores the head of the new reversed list, initialized after the first reversal.
    5. 'prev' tracks the tail of the previous reversed group to connect it with the current reversed group.
    6. The reversal is done in-place, using constant extra space and without using recursion or auxiliary data structures.
    7. Time Complexity: O(n), where n is the number of nodes; Space Complexity: O(1), constant auxiliary space.
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* ptr = head;
        Node* prev = NULL, *temp = NULL;
        Node* newHead = NULL;
        int i;
        
        while (ptr != NULL) {
            Node* tail = ptr; 
            Node* newPrev = NULL;

            for (i = 0; i < k && ptr != NULL; i++) {
                temp = ptr->next;
                ptr->next = newPrev;
                newPrev = ptr;
                ptr = temp;
            }
            
            if (newHead == NULL) {
                newHead = newPrev;
            }
            
           
            if (prev != NULL) {
                prev->next = newPrev;
            }

            prev = tail;

            if (i < k) {
                prev->next = ptr;
                break;
            }
        }
        return newHead;
    }
};