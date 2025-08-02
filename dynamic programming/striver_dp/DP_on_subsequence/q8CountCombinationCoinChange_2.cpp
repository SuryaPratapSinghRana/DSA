class Solution {
    int ways(int ind,int target,vector<int>& coins, vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(target%coins[ind]==0)
              return 1;
            else
              return 0;
        }
        if(dp[ind][target]!=-1)
          return dp[ind][target];
          int not_take=ways(ind-1,target,coins,dp);
          int take=0;
          if(target>=coins[ind])
          {
            take=ways(ind,target-coins[ind],coins,dp);
          }
          return dp[ind][target]=not_take+take;
      }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return ways(n-1,amount,coins,dp);
        // Tabulation
        // for(int i=0;i<=amount;i++)
        // {
        //     if(i%coins[0]==0)
        //      dp[0][i]=1;
        //     else
        //      dp[0][i]=0;
        // }
        // for(int ind=1;ind<n;ind++)
        // {
        //    for(int target=0;target<=amount;target++)
        //    {
        //     int not_take=dp[ind-1][target];
        //   int take=0;
        //   if(target>=coins[ind])
        //   {
        //     take=dp[ind][target-coins[ind]];
        //   }
        //   dp[ind][target]=not_take+take;
        //    }
        // }
        // return dp[n-1][amount];
        
    }
};