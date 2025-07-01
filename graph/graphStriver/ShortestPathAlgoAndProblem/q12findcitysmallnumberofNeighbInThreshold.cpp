class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            
            vector<vector<int>>dist(n,vector<int>(n,1e8));
            for(int i=0;i<n;i++)
            {
                dist[i][i]=0;  // diagonal khud ka khud se dist 0 hoga
            }
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                dist[u][v]=w;
                dist[v][u]=w;
            }
           for(int via=0;via<n;via++)
           {
            for(int u=0;u<n;u++)
            {
                for(int v=0;v<n;v++)
                {
                    if(dist[u][via]+dist[via][v]<dist[u][v])
                    {
                        dist[u][v]=dist[u][via]+dist[via][v];
                    }
                }
            }
           }
         // now traversing dist matrix which have shortest distance all node to all node
           int cityno=-1;
           int  mincityreach=n;
           for(int u=0;u<n;u++)
           { int count=0;
            for(int v=0;v<n;v++)
            {
                if(dist[u][v]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=mincityreach)
            {
                cityno=u;
                mincityreach=count;
            }
    
           }
    
           return cityno;
            
        }
    };