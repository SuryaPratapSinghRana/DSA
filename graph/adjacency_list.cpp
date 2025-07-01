#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
     unordered_map<int,list<int>> adj;
     void add(int u,int v,bool direction)
     {
        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
     }
     void print_list(){
        for(auto i:adj)
        {
           cout<<i.first<<"-->";
           for(auto j:i.second)
           {
             cout<<j<<",";
           }
           cout<<endl;
        }
     }
};
int main()
{
   int n;
   cout<<"enter the number of nodes ";
   cin>>n;
   cout<<" enter the number of edges ";
   int m;
   cin>>m;
   graph g;
   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    // creating an undirected graph
    g.add(u,v,0);
   }
   // print graph
   g.print_list();
    return 0;
}