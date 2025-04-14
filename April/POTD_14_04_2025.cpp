/* 
1. Initialize the Graph:
   - Create an adjacency list to represent the directed graph.
   - Initialize an in-degree map to store incoming edge counts for each character.
   - Extract all unique characters from the given words.
   
2. Build Character Dependencies:
   - Compare adjacent words and determine precedence based on the first differing character.
   - If word1[j] appears before word2[j], add a directed edge word1[j] → word2[j] in the graph.
   - Increase the in-degree of word2[j].
   - If word1 is longer than word2 but word2 is a prefix, return an empty string (invalid order).

3. Perform Topological Sorting (Kahn’s Algorithm - BFS):
   - Identify characters with zero in-degree and push them into a queue.
   - Process nodes in queue:
     - Append the current character to the result string.
     - Reduce in-degree of its neighbors and enqueue them if they reach zero in-degree.

4. Validate Result and Return Order:
   - If all unique characters are present in the final order, return it.
   - If some characters remain unprocessed (cycle detected), return an empty string.

Time Complexity:
- Graph Construction: O(N * M), where N is the number of words and M is the average word length.
- Topological Sorting: O(V + E), where V is the number of unique characters and E is the number of dependencies.
- Overall Complexity: O(N * M + V + E), ensuring efficiency for given constraints.

Space Complexity:
- Graph & In-degree map: O(V + E), storing adjacency list and in-degree counts.
- Queue for BFS: O(V), storing characters with zero in-degree.
- Total Space Complexity: O(V + E), keeping memory usage optimized.

This structured approach ensures correct character ordering in an alien language efficiently!
*/



class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDeg;
        unordered_set<char> c;

        for (const auto& word : words) {
            for (char ch : word) {
                c.insert(ch);
                graph[ch] = {}; 
                inDeg[ch] = 0;
            }
        }


        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i], word2 = words[i + 1];
            int minLen = min(word1.size(), word2.size());
            bool foundOrder = false;

            for (int j = 0; j < minLen; ++j) {
                if (word1[j] != word2[j]) {
                    graph[word1[j]].push_back(word2[j]);
                    inDeg[word2[j]]++;
                    foundOrder = true;
                    break;
                }
            }

            if (!foundOrder && word1.size() > word2.size()) return "";
        }

        queue<char> q;
        string order;
        
        for (const auto& ch : c) {
            if (inDeg[ch] == 0) q.push(ch);
        }

        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            order += cur;

            for (char neighbor : graph[cur]) {
                if (--inDeg[neighbor] == 0) q.push(neighbor);
            }
        }

        return (order.size() == c.size()) ? order : ""; 
    }
};