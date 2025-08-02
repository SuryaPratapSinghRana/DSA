class Solution {
public:
// memo by 2d dp
    int coin(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(amount==0)  // i dont need to pick any coin their already made that amount
              return 0;
            else if(amount%coins[0]==0)
              return amount/coins[0];
             else
              return 1e9;    
        }
           return 1e9;
        if(dp[ind][amount]!=-1)
          return dp[ind][amount];
        int take=INT_MAX;
        int not_take=coin(ind-1,amount,coins,dp);
        if(amount>=coins[ind])
        {
            take=1+coin(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(not_take,take);
    }

    // memo by 1d dp
    int fun2(int amount,vector<int>& coins,vector<int>&dp)
    {
        if(amount==0)
          return 0;
        if(dp[amount]!=-1)
          return dp[amount];
        int ans=1e9;
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amount)
            {
                int subans=1+fun2(amount-coins[i],coins,dp);
                ans=min(ans,subans);
            }
        }
       return dp[amount]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));  // for 2D dp
    //    int result=coin(coins.size()-1,amount,coins,dp);  // 2D dp ke liye
       vector<int>dp(amount+1,-1);  // for 1D dp 
      int result =fun2(amount,coins,dp);  // for 1D dp memo
       return result>=1e9?-1:result;
       dp[0]=0;
    //    tablation for 1d dp
       for(int amt=1;amt<=amount;amt++)
       {
         int ans=1e9;
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amt)
            {
                int subans=1+dp[amt-coins[i]];
                ans=min(ans,subans);
            }
        }
         dp[amt]=ans;

       }
       return dp[amount]>=1e9?-1:dp[amount];
    }
};