#include <bits/stdc++.h>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<bool> blue(n, false);
        vector<bool> green(n, false);
        for (int i = 0; i < n; i++) {
            if (blue[i] == false && green[i] == false) {
                q.push(i);
                blue[i] = true;
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto it : graph[u]) {
                    if (blue[u] == true && blue[it] == true) {
                        return false;
                    } else if (green[u] == true && green[it] == true) {
                        return false;
                    } else if (green[u] == true && blue[it] == false) {
                        blue[it] = true;
                        q.push(it);
                    } else if (blue[u] == true && green[it] == false) {
                        green[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        return true;
    }
    
};