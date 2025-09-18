/*
    1. This function finds the next greater element for each element in the array from its right side.
    2. It initializes a stack and pushes all elements except the last one in reverse order to simulate right-side traversal.
    3. A result vector `v` is initialized with -1, assuming no greater element exists by default.
    4. Starting from the last element, it pops from the stack until it finds a greater element or the stack becomes empty.
    5. If a greater element is found, it is stored in the result vector at the current index.
    6. The current element is then pushed onto the stack to be considered for earlier elements.
    7. Time Complexity: O(n), as each element is pushed and popped at most once; Space Complexity: O(n), due to the stack and result vector.
*/

class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        
        for(int j=n-2;j>=0;j--) st.push(arr[j]);
        
        vector<int> v(n,-1);
        int i=n-1;
        
        while(i>=0){
            while(st.size() and st.top()<=arr[i]) st.pop();
            if(st.size()) v[i]=st.top();
            st.push(arr[i--]);
        }
        
        return v;
    }
};