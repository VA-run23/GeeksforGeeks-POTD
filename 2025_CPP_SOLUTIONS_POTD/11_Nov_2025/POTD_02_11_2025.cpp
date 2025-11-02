/*
    1. This function computes the maximum number of edges that can be added to a DAG without forming cycles, using topological sorting.
    2. It builds an adjacency matrix `graph` and an indegree array `indeg` from the input edge list.
    3. Kahn's algorithm is applied to perform a topological sort, storing the result in `topo`.
    4. The nested loop iterates over all forward pairs (i < j) in the topological order to count potential edges.
    5. It checks if an edge from topo[i] to topo[j] already exists in `graph`; if not, it increments `ans`.
    6. The final result `ans` is the number of additional edges that can be safely added without creating cycles.
    7. Time Complexity: O(V² + E), Space Complexity: O(V²) due to adjacency matrix and topological sort.
*/

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
               
        int e = edges.size();
        vector<int> topo;
        vector<vector<int>> graph(V, vector<int>(V, 0));
        vector<int> indeg(V, 0);
        
        for(auto i: edges){
            graph[i[0]][i[1]] = 1;
            indeg[i[1]]++;
        }
        
        queue<int>q;
        
        for(int i = 0; i<V; i++){
            if(indeg[i] == 0)q.push(i);
        }
 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i = 0; i<V; i++){
                if(graph[node][i]){
                    indeg[i]--;
                    if(indeg[i] == 0){
                        q.push(i);
                    }
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i<V; i++){
            for(int j = i+1; j<V; j++){
                if(!graph[topo[i]][topo[j]]){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
