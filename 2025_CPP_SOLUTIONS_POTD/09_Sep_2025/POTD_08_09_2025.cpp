/*
    1. This code implements Merge Sort for a singly linked list using recursion and the slow-fast pointer technique.
    2. The getMiddle function finds the middle node to split the list into two halves for recursive sorting.
    3. The merge function recursively merges two sorted linked lists into one sorted list.
    4. The mergeSort function splits the list, recursively sorts both halves, and merges them.
    5. The base case for mergeSort is when the list is empty or has only one node (already sorted).
    6. Time Complexity: O(n log n) — each split takes O(log n) levels and merging takes O(n) per level.
    7. Space Complexity: O(log n) due to recursive call stack (not counting list nodes reused in-place).
*/

class Solution {
  public:
    Node* getMiddle(Node* head){
        if (!head) return head;
        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }
    Node* mergeSort(Node* head) {
       if (!head || !head->next)
            return head;

        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->next;
        middle->next = nullptr; 

        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMiddle);

        return merge(left, right); 
    }
};