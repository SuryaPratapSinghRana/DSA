class Solution {
int Stair(int n,vector<int>&dp)
{
     if(n==1)
         return 1;
        if(n==2)
         return 2;
         if(dp[n]!=-1)
           return dp[n];
         return dp[n]=Stair(n-1,dp)+Stair(n-2,dp);
}
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return Stair(n,dp);
    }
};