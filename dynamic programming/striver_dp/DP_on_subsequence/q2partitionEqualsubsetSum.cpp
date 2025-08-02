class Solution {
public:
   bool subsetsum(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp)
   {
    if(sum==0)
    {
        return true;
    }
    if(ind==0)
    {
        if(arr[0]==sum)
         return true;
        return false;
    }
    if(dp[ind][sum]!=-1)
      return dp[ind][sum];
    bool not_take=subsetsum(ind-1,sum,arr,dp);
    bool take=false;
    if(sum>=arr[ind])
      take=subsetsum(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum]=(take || not_take);
   }
    bool canPartition(vector<int>& nums) {
        int sum1=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
        }
        if(sum1%2!=0)
         return false;
        int sum=sum1/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return subsetsum(n-1,sum,nums,dp);
    }
};