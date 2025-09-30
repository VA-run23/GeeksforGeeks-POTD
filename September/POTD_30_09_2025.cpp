/*
    1. This function generates all binary strings of length 'n' using a breadth-first approach with a queue.
    2. It starts by pushing "0" and "1" into the queue, representing binary strings of length 1.
    3. For each level up to 'n', it dequeues each string and appends '0' and '1' to generate the next level of binary strings.
    4. This process continues until strings of length 'n' are formed in the queue.
    5. After the loop, all strings in the queue are collected into the result vector 'ans'.
    6. The binary strings are generated in ascending order due to the nature of BFS traversal.
    7. Time Complexity: O(2ⁿ), Space Complexity: O(2ⁿ), since there are 2ⁿ binary strings of length 'n'.
*/

class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        int count = 1;
        queue<string>q;
        q.push("0");
        vector<string>ans;
        q.push("1");
        while(count<n){
            count++;
            int k = q.size();
            while(k--){
                string a = q.front();
                q.pop();
                q.push(a +'0');
                q.push(a+'1');
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};