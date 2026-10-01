// Minimum Time to Finish Project

/*
 * 1. Represent tasks as nodes in a directed graph.
 *    - Dependencies form edges u → v (u must finish before v starts).
 *
 * 2. Compute indegree for each node.
 *    - indegree[v] = number of prerequisites for task v.
 *
 * 3. Initialize queue with tasks having indegree = 0.
 *    - These tasks can start immediately.
 *
 * 4. Track finish times.
 *    - finish[i] = earliest completion time of task i.
 *    - Initially finish[i] = duration[i].
 *
 * 5. Process tasks in topological order using Kahn’s algorithm.
 *    - Pop u from queue.
 *    - For each dependent v:
 *        finish[v] = max(finish[v], finish[u] + duration[v]).
 *
 * 6. Update indegree and push new free tasks.
 *    - Decrease indegree[v].
 *    - If indegree[v] == 0, push v into queue.
 *
 * 7. Final answer:
 *    - If all tasks processed → max finish time across tasks.
 *    - If cycle detected (processed < n) → return -1.
 */

class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Step 1: Build graph
        for (auto &dep : dependencies) {
            int u = dep[0];
            int v = dep[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: Initialize queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 3: Track finish times
        vector<int> finish = duration;
        int processed = 0;
        int projectTime = 0;

        // Step 4: Topological traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            projectTime = max(projectTime, finish[u]);

            for (int v : graph[u]) {
                finish[v] = max(finish[v], finish[u] + duration[v]);
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        // Step 5: Check cycle
        return (processed == n) ? projectTime : -1;
    }
};

// 🔑 Key Points
// - Graph + indegree array tracks dependencies.
// - Kahn’s algorithm ensures valid topological order.
// - Finish time of each task = longest path to it.
// - Answer = maximum finish time (critical path).
// - Cycle detection: processed < n → return -1.
// - Time complexity: O(n + m).
// - Space complexity: O(n + m).