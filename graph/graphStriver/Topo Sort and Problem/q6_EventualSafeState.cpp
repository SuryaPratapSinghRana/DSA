
// approach 1:using kahns algorithm
class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int v=graph.size();
            vector<vector<int>>revadj(v);
            vector<int>indegree(v,0),ans;
            // doing edges reverse
            for(int i=0;i<v;i++)
            {
                for(auto it:graph[i])
                {
                    revadj[it].push_back(i);
                    // indegree for i increament
                    indegree[i]++;
                }
            }
            queue<int>q;
            for(int i=0;i<v;i++)
            {
                if(indegree[i]==0)
                 {q.push(i);
                   ans.push_back(i);
                 }
            }
    
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto it:revadj[u])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                        ans.push_back(it);
                    }
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
    
        }
    };

// approach 2: using cycle dectection in directed using dfs

class Solution {
    public:
    bool checkcycleDFS(int node,vector<int>&vis,
    vector<int>&dfsvisited,vector<vector<int>>&adj,vector<int>&ans){
      vis[node]=1;
      dfsvisited[node]=1;
      for(auto neighbour:adj[node]){
        if(!vis[neighbour]){
          bool cycledetected= checkcycleDFS(neighbour,vis,dfsvisited,adj,ans);
          if(cycledetected){
            return true;
          }
        }
        else if(dfsvisited[neighbour])
        { 
          return true;
        }
      }
      ans.push_back(node);
      dfsvisited[node]=0;
      return false;
    }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int v=graph.size();
            vector<int>vis(v,0),dfsvis(v,0),ans;
            for(int i=0;i<v;i++)
            {
                if(vis[i]==0)
                {
                    checkcycleDFS(i,vis,dfsvis,graph,ans);
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
    };