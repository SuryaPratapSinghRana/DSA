class Solution {
public:
    int func(int row,int col,int &m,int &n,vector<vector<int>>&dp)
    {
        if(row==m-1 && col==m-1)
          return 1;
        if(dp[row][col]!=-1)
          return dp[row][col];
        int right=0,down=0;
        if(col+1<n)
        {
            right=func(row,col+1,m,n,dp);
        }
        if(row+1<m){
            down=func(row+1,col,m,n,dp);
        }

        return dp[row][col]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,m,n,dp);
    }
};