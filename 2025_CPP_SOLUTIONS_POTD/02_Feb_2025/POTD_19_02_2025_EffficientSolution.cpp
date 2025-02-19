///MOST: efficient solution
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        auto comp = [](Node* a, Node* b) {
            return a->data > b->data;
        };
        priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);

        for (Node* head : arr) {
            if (head) {
                pq.push(head);
            }
        }

        Node* dummy = new Node(0);
        Node* curr = dummy;

        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();

            curr->next = top;
            curr = curr->next;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy->next;
    }
};
