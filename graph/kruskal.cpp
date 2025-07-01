#include<vector>
class disjointset{
    vector<int> rank,parent,size;
    public:
    disjointset(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
      }
    }
    int findUpar(int node){
      if(node==parent[node]){
         return node;
      }
      else
        return parent[node]= findUpar(parent[node]);  // ab uska parent bhi ultimate hoga or jisko return karenge uska parent bhi
    }
    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
          parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
             parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;   // jab dono ki rank equal hogi tab increament hogi rank
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
             size[ulp_u]+=size[ulp_v];   
        }
    }

};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
                
            }
        }
        sort(edges.begin(),edges.end());
        int mstwt=0;
        disjointset ds(V);
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUpar(u)!=ds.findUpar(v)){
            mstwt+=wt;
            ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};