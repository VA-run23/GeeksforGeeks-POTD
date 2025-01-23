class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if (!head) return nullptr;

        for (Node* curr = head; curr != nullptr; curr = curr->next->next) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
        }

        for (Node* curr = head; curr != nullptr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        Node* newHead = head->next;
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
        }

        return newHead;
    }
};