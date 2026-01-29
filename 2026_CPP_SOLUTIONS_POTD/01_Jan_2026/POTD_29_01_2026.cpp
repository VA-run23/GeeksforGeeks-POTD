/*
    1. This function processes a stream of characters and tracks the first non-repeating character at each step.
    2. It uses an unordered_map `freq` to store frequency counts of each character encountered.
    3. A queue `q` maintains the order of characters to help identify the first non-repeating character.
    4. For each character, increment its frequency and push it into the queue.
    5. Continuously pop from the queue until the front is truly non-repeating (frequency == 1).
    6. Append '#' to the result if no non-repeating character exists, otherwise append the queue’s front.
    7. Time Complexity: O(n) (each character processed once); Space Complexity: O(n) (map + queue storage).
*/

class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char,int> freq;
        queue<char> q;
        string result = "";
        
        for(char c : s) {
            freq[c]++;
            q.push(c);
            
            while(!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
            
            if(q.empty()) result.push_back('#');
            else result.push_back(q.front());
        }
        
        return result;
    }
};