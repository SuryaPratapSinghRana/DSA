// approach 1

class Solution {
public:
    int func(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
          return 0;
        }
        if(i==j)
        {
          return nums[i];
        }
        if(dp[i][j]!=-1)
          return dp[i][j];
        int takei=nums[i]+min(func(i+2,j,nums,dp),func(i+1,j-1,nums,dp));
        int takej=nums[j]+min(func(i+1,j-1,nums,dp),func(i,j-2,nums,dp));
        return dp[i][j]=max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int p1=0;
        int p2=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        p1=func(0,nums.size()-1,nums,dp);
        p2=sum-p1;
        if(p1>=p2)
          return true;
        else
          return false;
    }
};

// approach 2  difference dekhenge jis path pe max hoga 

class Solution {
public:
    int func(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
          return 0;
        }
        if(i==j)
        {
          return nums[i];
        }
        if(dp[i][j]!=-1)
          return dp[i][j];
        int takei=nums[i]-func(i+1,j,nums,dp);
        int takej=nums[j]-func(i,j-1,nums,dp);
        return dp[i][j]=max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return func(0,nums.size()-1,nums,dp)>=0;
    }
};