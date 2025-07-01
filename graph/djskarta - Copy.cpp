#include <bits/stdc++.h>
#include<list>
#include<set>
#include<unordered_map>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){ // or auto it:edges
        int u=vec[i][0];      // or int u=it[0];
        int v=vec[i][1];      // or int v=it[1];
        int w=vec[i][2];      // or int w=it[3];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> st;
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        // fetch top record
        auto top=*(st.begin());
        int nodedistance=top.first;
        int topnode=top.second;
        // remove top record now
        st.erase(st.begin());
        // traverse on neighbour
        for(auto neighbour:adj[topnode]){
            if(nodedistance + neighbour.second<dist[neighbour.first]){            
              auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
              // if record found then erase it
              if(record!=st.end()){
                  st.erase(record);
              }
              // distance update
              dist[neighbour.first]=nodedistance+neighbour.second;
              // record push in set
              st.insert(make_pair(dist[neighbour.first],neighbour.first));

            }
        }
    }
    return dist;
}
