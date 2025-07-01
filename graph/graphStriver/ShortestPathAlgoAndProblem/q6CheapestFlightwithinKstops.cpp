class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            // make adjacency list
            vector<vector<pair<int,int>>>adj(n);
            for(int i=0;i<flights.size();i++)
            {
                int u=flights[i][0];
                int v=flights[i][1];
                int w=flights[i][2];
                adj[u].push_back({v,w});
            }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e8);
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto front=q.front();
            int stop=front.first;
            int u=front.second.first;
            int distu=front.second.second;
            q.pop();
            if(stop>k)continue;
            for(auto it:adj[u])
            {
                int v=it.first;
                int weight=it.second;
                if(distu+weight<dist[v] && stop<=k)
                {
                    dist[v]=distu+weight;
                    q.push({stop+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==1e8)
          return -1;
        else
          return dist[dst];
        }
    };