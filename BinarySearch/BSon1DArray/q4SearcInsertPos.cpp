class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int low=0;
            int high=nums.size()-1;
            int mid;
            if(nums[high]<target)
              return high+1;
            int ans;
            while(low<=high){
                mid=(low+high)/2;
                if(nums[mid]>=target)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }    
            }
             return  ans;   
        }
    };