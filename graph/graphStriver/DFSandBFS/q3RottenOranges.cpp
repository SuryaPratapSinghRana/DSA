

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            int count=0,conv=0;
             vector<vector<int>>vis(m,vector<int>(n,0));
             queue<pair<pair<int,int>,int>>q;
             for(int i=0;i<m;i++)
             {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==2){
                        q.push({{i,j},0});
                        vis[i][j]=2;
                    }
                    if(grid[i][j]==1)
                    {
                        count++;
                    }
    
                }
             }
             int tm=0;
             while(!q.empty())
             {
                int row=q.front().first.first;
                int colm=q.front().first.second;
                int t=q.front().second;
                q.pop();
                tm=max(t,tm);
               
                    int delrow[]={-1,0,1,0};
                    int delcolm[]={0,1,0,-1};
                    for(int i=0;i<4;i++)
                    {
                       
                            int nrow=row+delrow[i];
                            int ncolm=colm+delcolm[i];
                            if(nrow>=0 && nrow<m && ncolm>=0 && ncolm<n && vis[nrow][ncolm]!=2 && grid[nrow][ncolm]==1){
                                q.push({{nrow,ncolm},t+1});
                                vis[nrow][ncolm]=2;
                                conv++;
                            }
                    }
    
             }
             if(conv==count)
             return tm;
             else
             return -1;
    
        }
    };