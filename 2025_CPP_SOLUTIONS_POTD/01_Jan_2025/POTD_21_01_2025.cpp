//Better format is at bottom
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
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

////Format 2
class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        Node* dummy = new Node(0);
        dummy->next = head;

        Node* curr = dummy, *nex = dummy, *pre = dummy;
        int count = 0;

        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = pre->next;
            nex = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }

        return dummy->next;
    }
};
