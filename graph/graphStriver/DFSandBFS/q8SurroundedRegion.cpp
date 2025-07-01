class Solution {
    public:
        void dfs(int row, int colm, vector<vector<char>>&vis, vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vis[row][colm] ='O';
                    int delrow[]={0,-1,0,1};
                   int delcolm[]={-1,0,1,0};
                   for(int i=0;i<4;i++)
                   {
                      int irow=delrow[i]+row;
                      int icolm=delcolm[i]+colm;
                     if (m>irow && irow>= 0 && n>icolm && icolm>= 0 &&
                        vis[irow][icolm] =='X' && grid[irow][icolm]=='O') {
                         dfs(irow,icolm,vis,grid);
                    }
                      
                   }
           
        }
        void solve(vector<vector<char>>& grid) {
           int m = grid.size();
            int n = grid[0].size();
            vector<vector<char>>vis(m,vector<char>(n,'X'));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0 || j==0 || i==m-1 || j==n-1)
                    {
                        if(grid[i][j]=='O' && vis[i][j]=='X')
                        {
                            dfs(i,j,vis,grid);
                        }
                    }
                }
            }
            
            grid=vis;
        }
    };
    
    
    
    
    
                    