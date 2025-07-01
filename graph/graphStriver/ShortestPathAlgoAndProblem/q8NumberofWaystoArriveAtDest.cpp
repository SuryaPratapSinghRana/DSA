class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>>adj(n);
            for(auto it:roads)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
            vector<long long>dist(n,LLONG_MAX),ways(n,0);
            dist[0]=0;
            ways[0]=1;
            pq.push({0,0});
            int mod=1e9+7;
            while(!pq.empty())
            {
                auto f=pq.top();
                pq.pop();
                int u=f.second;
                long long uw=f.first;
                if(uw>dist[u]) continue;
                for(auto it:adj[u])
                {
                    int v=it.first;
                    long long vw=it.second; 
                    
                    if(uw+vw<dist[v])
                    {
                        ways[v]=ways[u]%mod;
                        dist[v]=uw+vw;
                        pq.push({uw+vw,v});
                    }
                    else if(uw+vw==dist[v])
                    {
                        ways[v]=(ways[v]+ways[u])%mod;
                    }
                }
            }
            return ways[n-1];
            
        }
    };