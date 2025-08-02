You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

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
        int not_take=maxrob(index-1,dp,nums);
        int  take=nums[index]+maxrob(index-2,dp,nums);
        return dp[index]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums){
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