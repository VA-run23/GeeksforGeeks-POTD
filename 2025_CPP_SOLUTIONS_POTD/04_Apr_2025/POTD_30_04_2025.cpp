/*
    This function detects and counts the number of nodes in a loop using Floyd’s Cycle Detection Algorithm.
    Two pointers, slow and fast, traverse the list at different speeds to detect a cycle.
    If they meet, a loop is present, and we pass the meeting point to a helper function.
    The helper function counts the nodes in the loop by traversing from the meeting node until it loops back.
    Time Complexity: O(N), where N is the total number of nodes in the list.
    Space Complexity: O(1), as no extra space is used besides a few pointers.
    This approach works reliably regardless of node values and handles all edge cases efficiently.
*/


class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return countLoopLength(slow);
            }
        }

        return 0;
    }

    int countLoopLength(Node *loop_node){
        Node *temp = loop_node;
        int count = 1;
        while(temp->next != loop_node){
            count++;
            temp = temp->next;
        }
        return count;
    }
};