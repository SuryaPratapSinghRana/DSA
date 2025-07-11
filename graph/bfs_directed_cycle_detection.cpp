#include<unordered_map>
#include<list>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first-1; // kyunki node 1 se suru h yaha isliye -1 kiya h
        int v=edges[i].second-1;
        adj[u].push_back(v);
    }
    // find all indegree
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    // 0 indegree walo ko push kar do
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    // do bfs
    int count=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        // increament count
        count++;
        //neigbour indegree update
        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }
   if(count==n)
   {
     return false;
   }
   return true;

  
}