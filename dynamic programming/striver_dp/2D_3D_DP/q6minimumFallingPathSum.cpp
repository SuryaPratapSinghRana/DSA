
// memoization giving tle in some large test case

class Solution {
public:
int func(int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(col<0 || col>=matrix[0].size())
           return 1e8;
        if(row==matrix.size())
        {
            return 0;
        }
        if(dp[row][col]!=-1)
          return dp[row][col];
        int down=matrix[row][col]+func(row+1,col,matrix,dp);
        int diagonalyleft=matrix[row][col]+func(row+1,col-1,matrix,dp);
        int diagonalyright=matrix[row][col]+func(row+1,col+1,matrix,dp);
        return dp[row][col]=min(down,min(diagonalyleft,diagonalyright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int mini=1e8;
        
        // first row ke har colm se chalke dekhenge jo min hoga wo answer h
        for(int i=0;i<n;i++){
            mini=min(mini,func(0,i,matrix,dp));
        }
        return mini;
    }
};


// this tabulation is working

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
  int n = matrix.size();
    vector<vector<int>> dp = matrix;

    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            int down = dp[row + 1][col];
            int diagLeft = col > 0 ? dp[row + 1][col - 1] : INT_MAX;
            int diagRight = col < n - 1 ? dp[row + 1][col + 1] : INT_MAX;

            dp[row][col] = matrix[row][col] + min({down, diagLeft, diagRight});
        }
    }

    return *min_element(dp[0].begin(), dp[0].end());
    }
};