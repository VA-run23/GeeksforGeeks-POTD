struct details{
    Node* curr ;
    Node* next;
    int len = 0;
    bool end = false;
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int size = arr.size();
        Node* firstHead = nullptr;
        Node* last = nullptr;
        int totalLen = 0;
        struct details info[size];

        for (int i = 0; i < size; i++) {
            info[i].curr = arr[i];
            info[i].next = arr[i] ? arr[i]->next : nullptr;
            Node* temp = arr[i];
            while (temp != nullptr) {
                info[i].len++;
                temp = temp->next;
            }
            totalLen += info[i].len;
        }

        for (int i = 0; i < totalLen; i++) {
            Node* currSmall = nullptr;
            int currentI = -1;

            for (int j = 0; j < size; j++) {
                if (!info[j].end && (currSmall == nullptr || info[j].curr->data < currSmall->data)) {
                    currSmall = info[j].curr;
                    currentI = j;
                }
            }

            if (firstHead == nullptr) {
                firstHead = currSmall;
                last = currSmall;
            } else {
                last->next = currSmall;
                last = currSmall;
            }

            if (info[currentI].next == nullptr) {
                info[currentI].end = true;
            } else {
                info[currentI].curr = info[currentI].next;
                info[currentI].next = info[currentI].next->next;
            }
        }

        return firstHead;
    }
};