//Pairwise Merging
//TC: O(Nlogk)
class Solution {
public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* ptr1 = l1;
        Node* ptr2 = l2;

        while (ptr1 && ptr2) {
            if (ptr2->data < ptr1->data) {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            } else {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            curr = curr->next;
        }

        if (ptr1) {
            curr->next = ptr1;
        }

        if (ptr2) {
            curr->next = ptr2;
        }

        Node* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }

    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        if (n == 0) return NULL;

        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                arr[i] = mergeTwoLists(arr[i], arr[n - 1 - i]);
            }
            n = (n + 1) / 2;
        }

        return arr[0];
    }
};
