class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if (head == NULL) return false;
        Node* hare = head;
        Node* turtle = head;
        while(hare != NULL && hare->next != NULL) {
            turtle = turtle->next;
            hare = hare->next->next;
            if(turtle == hare) {
                return true;
            }
        }
        return false;
    }
};

// Inside the while loop, it is necessary to first check if 'hare' is not NULL
// and then check if 'hare->next' is not NULL before accessing 'hare->next->next'.
// This ensures that we do not attempt to access or dereference a NULL pointer,
// which could lead to runtime errors.