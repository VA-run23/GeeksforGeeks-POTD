/*
   1. The function first handles edge cases: if the list is empty or has only one node, it is trivially a palindrome.
   2. Using slow and fast pointers, it finds the middle of the linked list (slow stops at mid, fast reaches end).
   3. Starting from the middle, it reverses the second half of the linked list in-place.
   4. After reversal, 'prev' points to the head of the reversed second half.
   5. Two pointers (p1 from start, p2 from reversed half) are used to compare values node by node.
   6. If any mismatch is found, the function returns false; otherwise, it continues until p2 is exhausted.
   7. If all corresponding nodes match, the function returns true, confirming the list is a palindrome.
      → Time Complexity: O(n) (traversal + reversal + comparison)
      → Space Complexity: O(1) (in-place reversal, no extra data structures used)
*/

// Key Points:
// - Uses two-pointer technique to find the middle efficiently.
// - Reverses only the second half, minimizing space usage.
// - Compares first half with reversed second half for palindrome check.
// - Efficient solution with linear time and constant space.

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if (!head || !head->next) return true;


        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = nullptr;
        Node* curr = slow->next;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node* p1 = head;
        Node* p2 = prev;
        while (p2) {
            if (p1->data != p2->data) return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};