#include <vector>
#include <stack>
using namespace std;

class Solution {
    void finishtimeDFS(int node, vector<int> &vis, vector<vector<int>>& adj, stack<int> &st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                finishtimeDFS(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void Dfs(int node, vector<int> &vis, vector<vector<int>> &transpose) {
        vis[node] = 1;
        for(auto it : transpose[node]) {
            if(!vis[it]) {
                Dfs(it, vis, transpose);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Step 1: Fill stack with finishing times
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                finishtimeDFS(i, vis, adj, st);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> transpose(V);
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }

        // Step 3: DFS on reversed graph
        fill(vis.begin(), vis.end(), 0);
        int count = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();
            if(!vis[node]) {
                Dfs(node, vis, transpose);
                count++;
            }
        }
        return count;
    }
};
