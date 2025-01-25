class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        if (head == NULL) return NULL;
        
        Node* turtle = head;
        Node* rabbit = head;

        while (rabbit && rabbit->next) {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if (turtle == rabbit) {

                turtle = head;
                while (turtle != rabbit) {
                    turtle = turtle->next;
                    rabbit = rabbit->next;
                }
                return turtle;
            }
        }
        return NULL; 
    }
};