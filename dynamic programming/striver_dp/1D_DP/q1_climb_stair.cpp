class Solution {
int Stair(int n,vector<int>&dp)
{
       if(n==0)
          return 1;
         if(dp[n]!=-1)
           return dp[n];
        int onestep=1+Stair(n-1,dp);
        int twostep=0;
        if(n>=2)
        {
            twostep=1+Stair(n-2,dp);
        }
        return dp[n]=onestep+twostep;
}
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        if (n == 1) return 1;
        if (n == 2) return 2;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};