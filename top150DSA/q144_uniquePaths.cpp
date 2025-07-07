You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// memoization

class Solution {
public:
    int func(int row,int colm,vector<vector<int>>&nums,vector<vector<int>>&dp)
    {   
        if(row==nums.size()-1 && colm==nums[0].size()-1)
        {
            if(nums[row][colm]==0)
              return 1;
            else
              return 0;
        }
        if(nums[row][colm]==1)
        {
            return 0;
        }
        if(dp[row][colm]!=-1)
          return dp[row][colm];
        int right=0;
        int down=0;
        if (colm + 1 < nums[0].size()) {
            right =func(row, colm + 1,nums, dp);
        }
        if (row + 1 < nums.size()) {
            down =func(row + 1, colm,nums, dp);
        }
        return dp[row][colm] =right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return func(0,0,obstacleGrid,dp);
    }
};

// tabulation

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        //  tabulation
        dp[m-1][n]=1;
        dp[m][n-1]=0;
        for (int row = m - 1;row>=0; row--) {
             for (int colm = n - 1; colm >= 0; colm--) {
                long long right = 0;
                long long down = 0;
              if(obstacleGrid[row][colm]!=1)
              {

                if (colm + 1 <=obstacleGrid[0].size()) {
                    right = dp[row][colm+1];
                }
                if (row + 1 <=obstacleGrid.size()) {
                    down = dp[row+1][colm];
                }

              }
                dp[row][colm] = right + down;
            }
        }
        return dp[0][0];
    }
};