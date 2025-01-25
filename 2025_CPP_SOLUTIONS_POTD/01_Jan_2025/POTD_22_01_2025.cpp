class Solution {
private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummyHead = new Node(0);
        Node* curr = dummyHead;
        int carry = 0;

        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        Node* result = reverseList(dummyHead->next);
        delete dummyHead;

        
        while (result && result->data == 0 && result->next) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }

        return result;
    }
};