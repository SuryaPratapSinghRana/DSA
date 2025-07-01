// chatgpt

class Solution {
    public:
        string findOrder(vector<string> &words) {
            vector<int> adj[26];  
            vector<int> in_degree(26, 0); // Track in-degrees
            vector<int> present(26, 0);   // Track used characters
    
            // Mark all characters as present
            for (string word : words) {
                for (char c : word) {
                    present[c - 'a'] = 1;
                }
            }
    
            // Build Graph
            for (int i = 0; i < words.size() - 1; i++) {
                string s1 = words[i], s2 = words[i + 1];
                int minlen = min(s1.length(), s2.length());
                bool found = false;  
                for (int j = 0; j < minlen; j++) {
                    if (s1[j] != s2[j]) { 
                        int u = s1[j] - 'a';
                        int v = s2[j] - 'a';
                        adj[u].push_back(v);
                        in_degree[v]++; // Increase in-degree of v
                        found = true;
                        break; 
                    }
                }
                
                // Invalid case: "abc" comes before "ab"
                if (!found && s1.length() > s2.length()) {
                    return "";
                }
            }
    
            // Kahn's Algorithm (Topological Sorting using BFS)
            queue<int> q;
            string ans = "";
    
            for (int i = 0; i < 26; i++) {
                if (present[i] && in_degree[i] == 0) {
                    q.push(i);
                }
            }
    
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans += (node + 'a');
    
                for (auto neighbor : adj[node]) {
                    in_degree[neighbor]--;
                    if (in_degree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
    
            // Check for a cycle (if all present characters are not included)
            for (int i = 0; i < 26; i++) {
                if (present[i] && in_degree[i] > 0) {
                    return ""; // Cycle detected
                }
            }
    
            return ans;
        }
    };
    