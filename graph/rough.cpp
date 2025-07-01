#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    // create adjaceny list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
           int u=g[i].first.first;
           int v=g[i].first.second;
           int w=g[i].second;
           adj[u].push_back({v,w});
           adj[v].push_back({u, w});
    }
    vector<int> vis(n+1, 0);
    vector<int> parent(n+1, -1);
    vector<int> weight(n+1, INT_MAX);
    weight[1]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({1,0});
    while(!pq.empty()){
           auto peak=pq.top();
           pq.pop();
           vis[peak.second]=1;
           for(auto it :adj[peak.second]){
                  if(vis[it.first]==0 && it.second<weight[it.first]){
                         pq.push({ it.second,it.first});
                         parent[it.first]=peak.second;
                         weight[it.first]=it.second;
                  }
           }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
          ans.push_back({{parent[i],i},weight[i]});
    }
return ans;
}
