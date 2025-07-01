class Solution {
    public:
    void dfs(int row, int colm, vector<vector<int>>&vis, vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vis[row][colm] =1;
                 int delrow[]={0,-1,0,1};
                   int delcolm[]={-1,0,1,0};
                   for(int i=0;i<4;i++)
                   {
                      int irow=delrow[i]+row;
                      int icolm=delcolm[i]+colm;
                     if (m>irow && irow>= 0 && n>icolm && icolm>= 0 &&
                        vis[irow][icolm] ==0 && grid[irow][icolm]==1) {
                         dfs(irow,icolm,vis,grid);
                    }
                      
                   }
           
        }
        int numEnclaves(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            int count=0;
            vector<vector<int>>vis(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0 || j==0 || i==m-1 || j==n-1)
                    {
                        if(grid[i][j]==1 && vis[i][j]==0)
                        {
                            dfs(i,j,vis,grid);
                        }
                    }
                }
            }
    
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1 && vis[i][j]==0)
                    {
                        count++;
                    }
                }
            }
            
            return count;
        }
    };
    
    
    
    
    
    
                    