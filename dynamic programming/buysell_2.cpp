class Solution {
public:
    int n;
    int solve(int i,int canbuy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i==n)
         return 0;
        if(dp[i][canbuy]!=-1)
         return dp[i][canbuy];
        if(canbuy)
        {
            int buy=-prices[i]+solve(i+1,0,prices,dp);
            int notbuy=solve(i+1,1,prices,dp);
            return dp[i][canbuy]=max(buy,notbuy);
        }
        else
        {
            int sell=prices[i]+solve(i+1,1,prices,dp);
            int notsell=0+solve(i+1,0,prices,dp);
            return dp[i][canbuy]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // tabulation
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                if(canbuy)
        {
            int buy=-prices[i]+dp[i+1][0];
            int notbuy=dp[i+1][1];
            dp[i][canbuy]=max(buy,notbuy);
        }
        else
        {
            int sell=prices[i]+dp[i+1][1];
            int notsell=0+dp[i+1][0];
            dp[i][canbuy]=max(sell,notsell);
        }
            }
        }
        return dp[0][1];
            
    }
};