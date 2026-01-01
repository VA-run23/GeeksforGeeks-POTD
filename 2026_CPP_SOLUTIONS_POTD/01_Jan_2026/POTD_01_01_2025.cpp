/*
    1. First, the lengths of both linked lists (l1 and l2) are calculated by traversing each list fully.  
    2. The difference in lengths (diff) is computed to align both lists at the same starting distance from the intersection point.  
    3. The longer list’s head pointer is advanced by 'diff' nodes so both lists now have equal remaining lengths.  
    4. Then, both head pointers are moved forward simultaneously one node at a time.  
    5. When head1 == head2, it means the intersection node has been found.  
    6. If no intersection exists, both pointers will eventually become NULL and the function returns NULL.  
    7. Time Complexity: O(n + m), where n and m are lengths of the two lists; Space Complexity: O(1) since no extra memory is used.  
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int l1 = 0, l2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        
        while(temp1){
            temp1 = temp1->next;
            l1++;
        }
        
        while(temp2){
            temp2 = temp2->next;
            l2++;
        }
        
        int diff = abs(l1 - l2);
        if(l1 > l2){
            while(diff--) head1 = head1->next;
        } else {
            while(diff--) head2 = head2->next;
        }

       
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }

        return head1; 
    }
};