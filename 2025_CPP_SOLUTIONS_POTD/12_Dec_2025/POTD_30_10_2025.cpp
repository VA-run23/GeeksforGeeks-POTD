/*
    1. The function first reverses both input linked lists so addition can be done from least significant digit to most significant digit.
    2. A dummy head node is created to simplify handling of the resulting linked list while iterating.
    3. A loop runs until both lists are exhausted and carry becomes zero, adding corresponding digits and managing carry.
    4. Each computed digit (sum % 10) is appended as a new node to the result list, while carry is updated as sum / 10.
    5. After addition, the result list is reversed back to restore the correct order of digits (most significant digit first).
    6. Leading zeros are removed from the final result to ensure proper representation of the sum.
    7. Time Complexity: O(max(N, M)) where N and M are lengths of the two lists; Space Complexity: O(max(N, M)) for the output list.
*/

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