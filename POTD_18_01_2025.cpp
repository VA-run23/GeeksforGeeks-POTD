class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(head == NULL ||head->next == NULL ) return head;
        Node* prev = NULL;
        Node* temp = head, *ptr = head;
        while(ptr != NULL){
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
        
    }
};