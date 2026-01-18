/*
    1. First, we compute the frequency of each element using an unordered_map so we can quickly compare counts.
    2. We initialize the answer vector with -1 (default when no greater frequency element exists).
    3. We use a stack to keep indices of elements while scanning from right to left (important since we want "next" elements).
    4. For each element, we pop from the stack while the frequency of the stack’s top element is <= current element’s frequency.
    5. This ensures only candidates with strictly greater frequency remain in the stack.
    6. If the stack is not empty after popping, the top element is the next greater frequency element for arr[i].
    7. Finally, we push the current index onto the stack and continue; overall complexity is O(n) time and O(n) space.
*/

class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;
    
        vector<int> ans(n, -1);
        stack<int> st;  
    
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = arr[st.top()];
            }
            st.push(i);
        }
        return ans;
    }

};