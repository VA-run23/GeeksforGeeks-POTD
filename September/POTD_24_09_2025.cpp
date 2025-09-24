/*
    1. This class implements a queue with constant-time access to both minimum and maximum elements using two deques: minQ and maxQ.
    2. enqueue(x): Adds x to the queue and updates minQ and maxQ to maintain monotonic order; O(1) amortized time.
    3. dequeue(): Removes the front element and updates minQ/maxQ if the removed element was at their front; O(1) time.
    4. getFront(): Returns the front element of the queue; O(1) time.
    5. getMin(): Returns the minimum element from minQ's front; O(1) time.
    6. getMax(): Returns the maximum element from maxQ's front; O(1) time.
    7. Space complexity is O(n) for storing n elements in the queue and auxiliary deques.
*/

class SpecialQueue {
    queue<int> q;
    deque<int> minQ, maxQ;
  public:

    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);

        while (!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);

        while (!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if (q.empty()) return;
        int val = q.front();
        q.pop();
        if (!minQ.empty() && minQ.front() == val) minQ.pop_front();
        if (!maxQ.empty() && maxQ.front() == val) maxQ.pop_front();
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return minQ.front();
    }

    int getMax() {
        // Get maximum element
        return maxQ.front();
    }
};