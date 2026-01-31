/*
    1. This class implements k queues using an unordered_map<int, queue<int>> where each key maps to a separate queue.
    2. The constructor initializes the total capacity 'size' as n, representing the maximum number of elements across all queues.
    3. enqueue(x, i) inserts element x into queue i and decrements the global size counter.
    4. dequeue(i) removes and returns the front element of queue i, increments size, or returns -1 if the queue is empty.
    5. isEmpty(i) checks whether a specific queue i has no elements.
    6. isFull() checks if the entire array of capacity n is completely filled across all queues (size == 0).
    7. Time Complexity: O(1) for enqueue, dequeue, isEmpty, and isFull; Space Complexity: O(n) for storing up to n elements across all queues.
*/

class kQueues {
    unordered_map<int,queue<int>> mp;
    int size;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        size = n;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        mp[i].push(x);
        size--;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(isEmpty(i)) return -1;
        
        int val = mp[i].front();
        mp[i].pop();
        size++;
        return val;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return mp[i].empty();
    }

    bool isFull() {
        // check if array is full
        return size == 0;
    }
};