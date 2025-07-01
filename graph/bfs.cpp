#include<unordered_map>
#include<queue>
#include<vector>
#include<set>
void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,
vector<int> &ans,int i)
{
  queue<int> q;
  q.push(adj[i][0]);
  visited[adj[i][0]]=true;
  while(!q.empty()){
      int front=q.front();
    q.pop();
    // store front node to answer
    ans.push_back(front);
    // check neighbour of front
     for(auto j:adj[front])
     {
       if (!visited[j]) {
         q.push(j);
         visited[j] = true;
       }
     }
  }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    unordered_map<int,bool> visited;
     for(int i=0;i<n;i++)
     {
         visited[adj[i][0]]=false;
     }
    int front;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(!visited[adj[i][0]])
        {
           bfs(adj,visited,ans,i);
        }
    }
    return ans;
}