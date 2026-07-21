// Maximum Reachable Index Difference

/*
 *    1. The problem asks for the maximum difference between indices when traversing the string
 *       starting from the first occurrence of 'a' and moving forward through consecutive characters.
 *    2. Build a map of character → deque of indices to store positions of each character.
 *    3. Use a min-heap (priority queue) to process characters in increasing order of index.
 *    4. Start from the first 'a' and push it into the heap.
 *    5. For each character, compute the difference between its index and the starting 'a' index.
 *    6. Then check if the next character (ch+1) exists; if so, push valid indices greater than current.
 *    7. Continue until no further characters can be processed.
 *    8. Return the maximum difference found, or -1 if 'a' does not exist.
 *    9. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();
        unordered_map<char, deque<int>> mpp;
        
        // Store indices of each character
        for (int i = 0; i < n; i++) {
            mpp[s[i]].push_back(i);
        }
        
        // Min-heap: {index, character}
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        
        // If no 'a' exists, return -1
        if (mpp.find('a') == mpp.end()) {
            return -1;
        }
        
        int ind = mpp['a'][0];
        pq.push({ind, 'a'});
        
        int max_diff = 0;
        
        while (!pq.empty()) {
            int ch = pq.top().second;
            int idx = pq.top().first;
            pq.pop();
            
            // Update maximum difference
            max_diff = max(max_diff, idx - ind);
            
            // Process next character (ch+1)
            if (mpp.find(char(ch + 1)) != mpp.end()) {
                deque<int> dq = mpp[char(ch + 1)];
                while (!dq.empty()) {
                    if (dq.front() > idx) {
                        pq.push({dq.front(), char(ch + 1)});
                    }
                    dq.pop_front();
                    if (dq.empty()) {
                        mpp.erase(char(ch + 1));
                    }
                }
            }
        }
        
        return max_diff;
    }
};

// Key Points
// 1. Start traversal from the first 'a'.
// 2. Use priority queue to process indices in increasing order.
// 3. Track maximum difference between current index and starting index.
// 4. Move to next character (ch+1) only if it exists in the string.
// 5. Efficiently handles multiple occurrences using deques.
// 6. Returns -1 if 'a' is absent.
// 7. Balanced use of heap + map ensures O(n log n) performance.