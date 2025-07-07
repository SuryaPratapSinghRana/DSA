class Solution {
    bool dfs(int u,vector<int>adj[],stack<int>&st,vector<int>&vis,vector<int>&dfsvis)
    {
        vis[u]=1;
        dfsvis[u]=1;
        for(auto v:adj[u])
        {
            if(vis[v]==0)
            { 
                bool cycle=dfs(v,adj,st,vis,dfsvis);
                if(cycle)
                {
                    return true;
                }
            }
            else if(dfsvis[v])
            {
                return true;
            }
        }

        //st.push(u);
        dfsvis[u]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
         for(auto i:prerequisites)
         {
            adj[i[1]].push_back(i[0]);
         }
         vector<int>vis(numCourses,0),dfsvis(numCourses,0);
         for(int i=0;i<numCourses;i++)
         {
            if(vis[i]==0)
            {
               if(dfs(i,adj,st,vis,dfsvis))
               {
                return false;
               }
            }
        }
        return true;
    }
};