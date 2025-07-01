#include<vector>
class Solution {
    private:
    int timer=1;
   void dfs(int node,int parent,vector<int> &vis,vector<vector<int>> adj,int tin[],int low[],vector<vector<int>> &bridges){
       vis[node]=1;
       tin[node]=timer;
       low[node]=timer;
       timer++;
       for(auto it:adj[node]){
           if(it==parent)continue;
           else if(vis[it]==0){
               dfs(it,node,vis,adj,tin,low,bridges);
               low[node]=min(low[it],low[node]);
               // now check bridge condition
               if(low[it]>tin[node]){
                   bridges.push_back({it,node});
               }
           }
           else{
               low[node]=min(low[node],low[it]);
           }
       }
   }
   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
    vector<vector<int>> bridges;
    dfs(0,-1,vis,adj,tin,low,bridges);
    return bridges;
    }
};