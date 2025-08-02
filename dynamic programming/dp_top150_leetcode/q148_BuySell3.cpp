Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// memoization

class Solution {
public:
    int n;
    int solve(int i,int canbuy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {   
        if(cap==0)
          return 0;
        if(i==n)
         return 0;
        if(dp[i][canbuy][cap]!=-1)
         return dp[i][canbuy][cap];
        if(canbuy)
        {
            int buy=-prices[i]+solve(i+1,0,cap,prices,dp);
            int notbuy=solve(i+1,1,cap,prices,dp);
            return dp[i][canbuy][cap]=max(buy,notbuy);
        }
        else
        {
            int sell=prices[i]+solve(i+1,1,cap-1,prices,dp);
            int notsell=0+solve(i+1,0,cap,prices,dp);
            return dp[i][canbuy][cap]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};

// Tabulation

int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0,1,2,prices,dp);
        // Tabulation
        // if cap==0 basecase
        for (int i = 0; i < n; i++) {
            for (int canbuy = 0; canbuy <= 1; canbuy++) {
                dp[i][canbuy][0] = 0;
            }
        }
        // if index==n basecase

        for (int canbuy=0; canbuy <= 1; canbuy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[n][canbuy][cap] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int canbuy=0; canbuy <= 1; canbuy++) {
                for (int cap = 1; cap <=2; cap++) {
                    if (canbuy) {
                        int buy = -prices[i] + dp[i + 1][0][cap];
                        int notbuy = dp[i + 1][1][cap];
                        dp[i][canbuy][cap] = max(buy, notbuy);
                    } else {
                        int sell = prices[i] + dp[i + 1][1][cap-1];
                        int notsell = 0 + dp[i + 1][0][cap];
                        dp[i][canbuy][cap] = max(sell, notsell);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};