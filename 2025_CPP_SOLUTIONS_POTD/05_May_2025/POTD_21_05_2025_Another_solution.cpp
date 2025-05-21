/*
    1. We initialize a priority_queue<int> maxHeap, which acts as a max heap to store the smallest k elements.
    2. We iterate through the multiplication table values i * j from 1 to m and 1 to n, pushing each into the heap.
    3. If the heap size exceeds k, we remove the largest element using maxHeap.pop() to maintain only the k smallest numbers.
    4. This ensures that the heap always contains the k smallest elements seen so far.
    5. After completing the nested loops, the largest element in the heap (maxHeap.top()) is the k-th smallest number.
    6. The priority queue maintains an efficient order with O(log k) complexity per insertion and deletion.
    7. This approach offers a tradeoff between simplicity and efficiency but is suboptimal compared to binary search.
*/

/*
        1. Binary Search (First Approach) is faster because it eliminates unnecessary computations by narrowing the search space logarithmically.
        2. Priority Queue (Second Approach) is slower since it iterates through all m * n elements and maintains a heap, leading to higher time complexity.
        3. Binary Search runs in O(m log(m × n)), while the priority queue approach runs in O(m × n × log k), making it inefficient for large values.
        4. Space Complexity: Binary search uses O(1) space, whereas the priority queue approach requires O(k) space to store elements.
        5. Heap operations (push/pop) are costly, whereas binary search only performs simple arithmetic and comparisons.
        6. Binary search leverages mathematical properties of the multiplication table, making it more optimal than brute-force heap insertion.
        7. For large constraints (m, n up to 30,000), binary search is the only feasible approach, while the heap-based method becomes impractical.
*/



class Solution {
public:
    int kthSmallest(int m, int n, int k) {
        priority_queue<int> maxHeap;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                maxHeap.push(i * j);
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }

        return maxHeap.top();
    }
};
