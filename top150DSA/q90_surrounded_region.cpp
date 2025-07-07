class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>&vis, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] ='O';
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) == abs(j)) {
                    continue;
                }
                int nrow = row + i;
                int ncol = col + j;
                if (m > nrow && nrow >= 0 && n > ncol && ncol >= 0 &&
                    vis[nrow][ncol] =='X' && grid[nrow][ncol]=='O') {
                     
                     dfs(nrow,ncol,vis,grid);
                }
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