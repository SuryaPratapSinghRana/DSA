Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// memoization
class Solution {
public:
    int func(int index,int row,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(row==triangle.size())
        {
            return 0;
        }
        if(dp[row][index]!=-1)
          return dp[row][index];
        return dp[row][index]=triangle[row][index]+min(func(index,row+1,triangle,dp),func(index+1,row+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,0,triangle,dp);
    }
};

// tabulation
 int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // make dp array for n+1 becuase is for nth row so make n+1
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // tabulation
        for(int row=n-1;row>=0;row--)
        {
          for(int index=0;index<triangle[row].size();index++)
          {
            dp[row][index]=triangle[row][index]+min(dp[row+1][index],dp[row+1][index+1]);
          }
        }
        return dp[0][0];
    }