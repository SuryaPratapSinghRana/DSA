class Solution {
public:
  void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis)
  {
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(!q.empty())
    { 
        auto it=q.front();
        q.pop();
        for(int row=-1;row<=1;row++)
        {
         for(int col=-1;col<=1;col++)
         {
                int nrow=it.first+row;
                int ncol=it.second+col;
                if((nrow>=0 && nrow<grid.size()) && ncol>=0  && ncol<grid[0].size() && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
               {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
        }
       }

    }
  }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
        }
    
};