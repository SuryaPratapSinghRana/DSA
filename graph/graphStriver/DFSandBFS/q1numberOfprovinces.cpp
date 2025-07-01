// Approach 1: dfs/bfs

class Solution {
    public:
    void soln(vector<int>adj[],int node,vector<bool>&vis){
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                soln(adj,i,vis);
            }
        }
    }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<int>adj[n];
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    }
                }
            }
            vector<bool>vis(n,0);
            int ans= 0;
            for(int i = 0;i<n;i++){
                if(!vis[i]){
                    soln(adj,i,vis);
                    ans++;
                }
            }
            return ans;
        }
    };


// Approach 2:Ayush Kumar disjoin set

class Solution {
    public:
       int findparent(int u,vector<int>&parent)
       {
        if(u==parent[u])
           return u;
        return parent[u]=findparent(parent[u],parent);
       }
       bool union1(int u,int v,vector<int>&parent,vector<int>&rank)
       {
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);
        if(pu==pv)
          return false;
        else
        {
            if(rank[pu]==rank[pv])
            {
                parent[pv]=pu;
                rank[pu]++;
            }
            else if(rank[pv]>rank[pu])
            {
                parent[pu]=pv;
            }
            else
            {
                parent[pv]=pu;
            }
        }
        return true;
       }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            
            int n=isConnected.size();
            vector<int>parent(n,0),rank(n,0);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(isConnected[i][j]!=0)
                    {
                    union1(i,j,parent,rank);
                    }
                }
            }
            int prov=0;
            for(int i=0;i<n;i++)
            {
                if(parent[i]==i)
                {
                    prov++;
                }
            }
            return prov;
        }
    };