/*
    1. Traverse the preorder array while keeping track of ancestors using a stack.
    2. Compare each element with its next value to determine parent-child relationships.
    3. If the current element is greater than the next, push it onto the stack as a potential ancestor.
    4. If the next element is greater, pop from the stack until a valid ancestor remains, marking the current node as a leaf.
    5. When popping happens, set the flag to 'true', meaning the current node has lost its ancestor relationship.
    6. If the flag is 'true', store the current node in the 'leaves' vector.
    7. The last element in the traversal is always a leaf and is added manually at the end.
*/


class Solution {
public:
    vector<int> leafNodes(vector<int>& p) {
        stack<int> st;
        vector<int> leaves;
        
        for (int i = 0, j = 1; j < p.size(); i++, j++) {
            bool flag = false;

            if (p[i] > p[j]) 
                st.push(p[i]);
            else {
                while (!st.empty() && p[j] > st.top()) {
                    st.pop();
                    flag = true;
                }
            }

            if (flag) 
                leaves.push_back(p[i]);
        }

        leaves.push_back(p.back());
        return leaves;
    }
};


