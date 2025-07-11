You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 


// memoization

class Solution {
    int maxrob(int index,vector<int>&dp,vector<int>&nums)
    {   
        if(index<0)
          return 0;
        if(index==0)
        {   
            return nums[index];
        }
        if(dp[index]!=-1)
          return dp[index];
        int not_take=maxrob(index-1,dp,nums );
         int   take=nums[index]+maxrob(index-2,dp,nums);
        return dp[index]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxrob(nums.size()-1,dp,nums);
    }
};

//  tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()==1)
          return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            int not_take=dp[i-1];
            int take=nums[i]+dp[i-2];
            dp[i]=max(take,not_take);

        }
        return dp[nums.size()-1];
    }
};