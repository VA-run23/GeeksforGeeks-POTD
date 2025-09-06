/*
    1. This code detects a loop in a linked list using Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
    2. Two pointers, 'slow' and 'fast', traverse the list at different speeds; if they meet, a loop exists.
    3. Once a loop is detected, the 'countLoopLength' function is called to calculate the loop's length.
    4. 'countLoopLength' starts from the meeting point and counts nodes until it loops back to the same node.
    5. If no loop is found, the function returns 0, indicating the list is linear.
    6. Time Complexity: O(N), where N is the number of nodes in the list (worst case traversal).
    7. Space Complexity: O(1), as no extra space is used beyond a few pointers.
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
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