class Solution {
public:
    void dfs(string u, string v, unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, int>& vis, double& ans, double mul) {
        if (u == v) {
            ans = mul;
            return;
        }
        vis[u] = 1;
        for (auto i : adj[u]) {
            if (vis[i.first] == 0) {
                dfs(i.first, v, adj, vis, ans, mul * i.second);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Build the adjacency list
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];

            // Check if both variables exist in the graph
            if (adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            // Run DFS to find the result
            unordered_map<string, int> vis;
            double val = -1.0;
            dfs(u, v, adj, vis, val, 1.0);
            ans.push_back(val);
        }

        return ans;
    }
};
