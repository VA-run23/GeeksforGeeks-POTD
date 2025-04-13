/*
1. If the input node is null, return null as there is no graph to clone.
2. Create a hash map clones to store mappings from original nodes to their cloned counterparts.
3. Initialize the cloning process by creating the first clone node and storing it in the hash map.
4. Use a queue for Breadth-First Search (BFS) to iterate through the original graph while cloning each node.
5. For each visited node, check its neighbors; if a neighbor isn't already cloned, create a new clone and add it to the queue.
6. Each cloned node gets its corresponding cloned neighbors linked appropriately, preserving the original graph structure.
7. Finally, return the reference to the cloned starting node.

Time Complexity: O(N + E), where N is the number of nodes and E is the number of edges (each node and edge is processed once).
Space Complexity: O(N), where N accounts for the storage of cloned nodes in the hash map and queue.

*/

class Solution {
    public:
      Node* cloneGraph(Node* node) {
          // code here
          if (!node) return nullptr;
          unordered_map<Node*, Node*> clones;
  
          Node* cloneNode = new Node(node->val);
          clones[node] = cloneNode;
  
          queue<Node*> q;
          q.push(node);
  
          while (!q.empty()) {
              Node* current = q.front();
              q.pop();
  
              for (Node* neighbor : current->neighbors) {
                  if (clones.find(neighbor) == clones.end()) {
                      clones[neighbor] = new Node(neighbor->val);
                      q.push(neighbor);
                  }
                  clones[current]->neighbors.push_back(clones[neighbor]);
              }
          }
          return cloneNode;
      }
  };