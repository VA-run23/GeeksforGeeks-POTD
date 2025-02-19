///MY OWN SOLUTION: Having complexity of o(N * k)

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
        // int size = sizeof(arr) / sizeof(arr[0]);
        int size = arr.size();
        Node* firstHead = nullptr;
        Node* currSmall= NULL;
        int totalLen = 0;
        Node* smallValPtr = arr[0];
        struct details info[size];
        for(int i  = 0; i<size; i++){
            info[i].curr = arr[i];
            info[i].next =arr[i] ->next;
            Node* temp  = arr[i];
            if(smallValPtr->data > arr[i]->data){
                smallValPtr = arr[i];
            }
            while(temp != NULL){
                info[i].len++;
                temp = temp->next;
            }
            totalLen+= info[i].len;
        }
        ///MERGING: HERE:
        for(int i  = 0; i<totalLen; i++){
            currSmall = nullptr;
            int currentI = -1;
            for (int j = 0; j < size; j++) {
                if (!info[j].end && (currSmall == NULL || currSmall->data > info[j].curr->data)) {
                    currSmall = info[j].curr;
                    currentI = j;
                }
            }
            if(i==0){
                firstHead = currSmall;
            }else{
              smallValPtr->next = currSmall;
            }
            smallValPtr = currSmall;         
            if(info[currentI].curr->next == NULL) {
                info[currentI].end = true;
            } else {
                info[currentI].curr = info[currentI].curr->next;
            }
        }
        return firstHead;
    }
};