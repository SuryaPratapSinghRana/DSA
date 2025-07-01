 class Solution {
  public:
   bool canweplace(vector<int> &nums,int dist, int k)
    {
        int countcow=1,last=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-last>=dist)
            {
                countcow++;
                last=nums[i];
            }
        }
        if(countcow>=k)
          return true;
        else
          return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {

       sort(nums.begin(),nums.end());
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int low=1,high=maxi-mini;
        int ans=-1;
       while(low<=high)
        {
            int mid=(low+high)/2;
            if(canweplace(nums,mid,k))
            {
               ans=mid;
               low=mid+1;   // right half mein is se bada anser dhoondo
            }
            else
            {
                high=mid-1;  // left half mein possible anser dhoondo
            }
        }
        return ans;  // or return high ek hi baat h
    }
};