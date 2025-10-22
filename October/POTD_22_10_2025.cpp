/*
    1. This function sorts a nearly sorted array where each element is at most 'k' positions away from its correct position.
    2. It uses a min-heap (priority_queue with greater<int>) to always keep track of the smallest element in the current window.
    3. Initially, elements are pushed into the heap one by one.
    4. Once the heap size exceeds 'k', the smallest element (top of the heap) is placed at the current index in the array.
    5. This ensures that the smallest among the next k+1 elements is placed in the correct position.
    6. After the loop, any remaining elements in the heap are popped and placed back into the array.
    7. This results in a fully sorted array in O(n log k) time using O(k) extra space.
*/

class Solution {
  public:
        void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        int n=arr.size();
        int ind=0;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[ind]=pq.top();
                ind++;
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            arr[ind]=pq.top();
            ind++;
            pq.pop();
        }
        
    }
};