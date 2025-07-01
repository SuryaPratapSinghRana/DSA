#include<iostream>
#include<vector>
using namespace std;
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
int main(){
   disjointset ds(7);
   ds.unionByRank(1,2);
   ds.unionByRank(2,3);
   ds.unionByRank(4,5);
   ds.unionByRank(6,7);
   ds.unionByRank(5,6);
   if(ds.findUpar(3)==ds.findUpar(7)){
    cout<<"belongs to same "<<endl;
   }
   else{
    cout<<"does not belongs to same "<<endl;
   }
   ds.unionByRank(3,7);
   if(ds.findUpar(3)==ds.findUpar(7)){
    cout<<"belongs to same ";
   }
   else{
    cout<<"does not belongs to same ";
   }
    return 0;
}