/*
    1. Create a min heap (priority queue) to store matrix elements 
        in ascending order for efficient retrieval of the smallest elements.
    2. Determine matrix dimensions (m rows, n columns) using size() 
        functions for iteration.
    3. Traverse the matrix row-wise and column-wise, pushing each 
        element into the min heap to maintain sorted order.
    4. Pop (k-1) elements from the min heap, ensuring that only 
        the kth smallest element remains at the top.
    5. Return the top element of the min heap, which is now the 
        kth smallest element in the matrix.
*/

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq; 
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                pq.push(matrix[i][j]);
            }
        }
        for(int i =0; i<k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};