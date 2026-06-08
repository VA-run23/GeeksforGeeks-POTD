// Delete Nodes with Greater on Right

/*
 *    1. Reverse the linked list to process nodes from right to left
 *    2. Track the maximum node encountered so far
 *    3. If the current node’s value is less than the maximum, delete it
 *    4. Otherwise, update the maximum node pointer
 *    5. Continue traversing until the end of the reversed list
 *    6. Reverse the list again to restore original order after deletions
 *    7. Time Complexity: O(N), Space Complexity: O(1)
 */

class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        if (!head || !head->next) return head;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        Node* maxNode = head;
        current = head->next;

        while (current != nullptr) {
            if (current->data >= maxNode->data) {
                maxNode = current;
            } else {
                maxNode->next = current->next;
            }
            current = current->next;
        }

        prev = nullptr;
        current = head;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }
};

// Key Points
// 1. Reverse the list to simplify deletion logic
// 2. Maintain a running maximum while traversing
// 3. Delete nodes smaller than the maximum encountered
// 4. Reverse the list again to restore original order
// 5. Works in linear time with constant extra space
// 6. Avoids recursion, making it memory efficient
// 7. Handles edge cases like empty list or single node gracefully`