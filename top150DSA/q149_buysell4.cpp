You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// memoizaion

class Solution {
public:
     int n;
    int solve(int i, int canbuy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (cap == 0)
            return 0;
        if (i == n)
            return 0;
        if (dp[i][canbuy][cap] != -1)
            return dp[i][canbuy][cap];
        if (canbuy) {
            int buy = -prices[i] + solve(i + 1, 0, cap, prices, dp);
            int notbuy = solve(i + 1, 1, cap, prices, dp);
            return dp[i][canbuy][cap] = max(buy, notbuy);
        } else {
            int sell = prices[i] + solve(i + 1, 1, cap - 1, prices, dp);
            int notsell = 0 + solve(i + 1, 0, cap, prices, dp);
            return dp[i][canbuy][cap] = max(sell, notsell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));
         return solve(0,1,k,prices,dp);
    }
};

//tabulation

int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        //  return solve(0,1,k,prices,dp);

         for (int i = 0; i < n; i++) {
            for (int canbuy = 0; canbuy <= 1; canbuy++) {
                dp[i][canbuy][0] = 0;
            }
        }
        // if index==n basecase

        for (int canbuy=0; canbuy <= 1; canbuy++) {
            for (int cap = 0; cap <= k; cap++) {
                dp[n][canbuy][cap] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int canbuy=0; canbuy <= 1; canbuy++) {
                for (int cap = 1; cap <=k; cap++) {
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
        return dp[0][1][k];
    }
};