Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

// memoization
class Solution {
public:
    int solve(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&dp,int &maxi)
    {
        if(i<0 || j<0)
          return 0;
        if(dp[i][j]!=-1)
           return dp[i][j];
            int left=solve(i,j-1,mat,dp,maxi);
            int dia=solve(i-1,j-1,mat,dp,maxi);
            int up=solve(i-1,j,mat,dp,maxi);
            if(mat[i][j]=='1')
            {
               int ans=1+min(left,min(dia,up));
               maxi=max(ans,maxi);
               return dp[i][j]=ans;
            }
            else
            { 
                return dp[i][j]=0;
            }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int maxi=0;
         solve(m-1,n-1,matrix,dp,maxi);
        return maxi*maxi;
    }
};

// tabulation

int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxi = 0;
        // base case intiallize 0 and make dp[m+1][n+1]
        // tabulation
        
        for (int i = 1; i <= m; i++) {
            for (int j =1; j <= n; j++) {
                int left = dp[i][j-1];
                int dia =dp[i-1][j-1];
                int up =dp[i-1][j];
                if (matrix[i-1][j-1] == '1') {
                    int ans = 1 + min(left, min(dia, up));
                    maxi = max(ans, maxi);
                      dp[i][j] = ans;
                } else {
                     dp[i][j] = 0;
                }
            }
        }

        return maxi*maxi;
    }