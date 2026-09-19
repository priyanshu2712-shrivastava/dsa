class Solution {
    int timer = 0;

    void dfs(int node, int parent,
             vector<int>& vis,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& adj,
             vector<vector<int>>& bridge) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto nei : adj[node]) {

            // Ignore the edge through which we came
            if (nei == parent)
                continue;

            if (!vis[nei]) {

                dfs(nei, node, vis, tin, low, adj, bridge);

                // Update low-link value
                low[node] = min(low[node], low[nei]);

                // Bridge condition
                if (low[nei] > tin[node]) {
                    bridge.push_back({node, nei});
                }

            } else {

                // Back edge
                low[node] = min(low[node], tin[nei]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridge;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, adj, bridge);
            }
        }

        return bridge;
    }
};