// The DSU class implements Disjoint Set Union, providing efficient union and find operations.
// It tracks parent nodes for each element and ranks for union-by-rank optimization.
    
// The find function uses path compression to find the root of a set and optimize future queries.
// The unite function connects two sets while ensuring minimal tree height using rank.

// The Solution class checks if removing edge {c, d} creates a disconnected graph.
// It initializes a DSU object and connects all edges except {c, d}.

// The isBridge method returns true if nodes c and d belong to different sets after edge removal.
// This indicates that edge {c, d} is a bridge in the graph.

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int u = find(x);
        int v = find(y);

        if (u != v) {
            if (rank[u] > rank[v])
                parent[v] = u;
            else if (rank[u] < rank[v])
                parent[u] = v;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        DSU dsu(V);
        
        for (auto &edge : edges) {
            if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c)) 
                continue;
            dsu.unite(edge[0], edge[1]);
        }
        return dsu.find(c) != dsu.find(d);
    }
};