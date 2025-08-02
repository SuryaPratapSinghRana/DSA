ou are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3

class Solution {
public:
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
          return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1)temp1.push_back(nums[i]);
            if(i!=0)temp2.push_back(nums[i]);
        }
        vector<int>dp(n,-1);
        int ans1=maxrob(n-2,dp,temp1);
        dp.assign(n,-1);
        int ans2=maxrob(n-2,dp,temp2);
        return max(ans1,ans2);
    }
};