Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

class Solution {
public:
    int func(int row, int colm, vector<vector<int>>& grid,
             vector<vector<int>>& dp) {
        // base case
        if (row == grid.size() - 1 && colm == grid[0].size() - 1) {
            return grid[row][colm];
        }
        if (dp[row][colm] != -1)
            return dp[row][colm];
        int right = 1e9;
        int down = 1e9;
        if (colm + 1 < grid[0].size()) {
            right = grid[row][colm] + func(row, colm + 1, grid, dp);
        }
        if (row + 1 < grid.size()) {
            down = grid[row][colm] + func(row + 1, colm, grid, dp);
        }
        return dp[row][colm] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,1e9));
        //  return func(0,0,grid,dp);

        // tabulation
        dp[m][n-1] =0;
        dp[m-1][n]=0;

        for (int row = m-1; row >= 0; row--) {
            for (int colm = n-1; colm >= 0; colm--) {
                int down = 1e9;
                int right=1e9;
                if (colm + 1 <=grid[0].size()) {
                    right = grid[row][colm] + dp[row][colm+1];
                }
                if (row + 1 <=grid.size()) {
                    down = grid[row][colm] + dp[row+1][colm];
                }
               dp[row][colm] = min(right, down);
            }
        }
        return dp[0][0];
    }
};