class Solution {
    public:
        int lowerbound(vector<int>& nums, int target) {
            int low=0;
            int high=nums.size()-1;
            int mid;
            int ans=-1;
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