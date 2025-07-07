/* 
    1. The function aims to find the next greater element for each item in the array from its right side.
    2. It initializes a stack and preloads all elements except the last one for later comparison.
    3. A result vector `v` is created, initialized with -1, assuming no greater element by default.
    4. Starting from the last element, it removes all smaller or equal elements from the stack.
    5. If a greater element exists at the top of the stack, it's set in the result vector.
    6. The current element is then pushed to the stack for future comparisons.
    7. Time Complexity: O(n); each element is pushed and popped at most once. Space Complexity: O(n) for stack and result vector.
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
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