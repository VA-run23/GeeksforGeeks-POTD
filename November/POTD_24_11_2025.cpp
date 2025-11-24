/*
    1. The code defines a DSU (Disjoint Set Union) class to efficiently manage connected components using union-find with path compression and union by size.
    2. The mstWt() function computes the MST (Minimum Spanning Tree) weight using Kruskal’s algorithm, optionally skipping one edge to test alternative MSTs.
    3. It iterates through sorted edges, unites disjoint sets, and accumulates weights while marking used edges; if MST is incomplete, returns -1.
    4. The secondMST() function first computes the primary MST weight, then tries removing each edge used in the MST to form alternative spanning trees.
    5. For each removed edge, mstWt() is called again to check if a valid spanning tree exists with higher weight, updating the second-best MST candidate.
    6. If no valid second MST is found, returns -1; otherwise, returns the minimum weight among all valid second MSTs greater than the primary MST.
    7. Time Complexity: O(E l   og E + V*E) ≈ O(E*V) in worst case (sorting + repeated MST checks); Space Complexity: O(V + E) for DSU arrays and edge storage.
*/

/* Key Points:
    - Uses Kruskal’s algorithm with DSU for MST construction.
    - Primary MST is computed once, then edges used are tested by exclusion.
    - Ensures second MST weight is strictly greater than the primary MST.
    - Efficient for moderate constraints (E up to 1e4, V up to 1e2).
*/

class Solution
{
public:
    class DSU
    {
    public:
        int n;
        vector<int> parent;
        vector<int> sz;

        DSU(int v)
        {
            n = v;
            parent.resize(n, 1);
            sz.resize(n, 1);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int Find(int u)
        {
            if (parent[u] == u)
                return u;
            return parent[u] = Find(parent[u]);
        }

        void Union(int u, int v)
        {
            int pu = Find(u);
            int pv = Find(v);
            if (pu == pv)
            {
                return;
            }

            if (sz[pv] > sz[pu])
            {
                parent[pu] = pv;
                sz[pv] += sz[pu];
            }
            else
            {
                parent[pv] = pu;
                sz[pu] += sz[pv];
            }
        }
    };

    int mstWt(int vertices, int to_not_use, vector<vector<int>> &edges, vector<int> &used)
    {
        int n = edges.size();
        int MstWt = 0;
        int count_edges = 0;

        DSU dsu(vertices);

        for (int i = 0; i < n; i++)
        {
            if (i == to_not_use)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (dsu.Find(u) != dsu.Find(v))
            {
                dsu.Union(u, v);
                MstWt += wt;
                count_edges++;
                used[i] = 1;
            }
        }

        if (count_edges != vertices - 1)
            return -1;
        return MstWt;
    }

    int secondMST(int n, vector<vector<int>> &edges)
    {
        // code here
        int m = edges.size();
        if (m <= n - 1)
            return -1;

        auto mysort = [&](const auto &a, const auto &b)
        {
            return a[2] < b[2];
        };

        sort(edges.begin(), edges.end(), mysort);
        vector<int> used(m, 0);
        int priMstWt = mstWt(n, -1, edges, used);
        if (priMstWt == -1)
            return -1;
        vector<int> copy_used = used;
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            if (copy_used[i] == 1)
            {
                int secondary_MstWt = mstWt(n, i, edges, used);
                if (secondary_MstWt != -1 && secondary_MstWt > priMstWt)
                {
                    ans = min(ans, secondary_MstWt);
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};