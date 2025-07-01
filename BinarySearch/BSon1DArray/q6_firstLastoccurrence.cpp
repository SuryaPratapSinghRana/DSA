// Approach 3: using binary search not using lower and uppper bound concept

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
          int first=-1,last=-1;
          int s=0,e=nums.size()-1;
          // finding first occerence
          while(s<=e)
          {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                first=mid;
                e=mid-1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
          }
          s=0,e=nums.size()-1;
           // finding last occerence
          while(s<=e)
          {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                last=mid;
                s=mid+1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
          }
          return {first,last};
        }
    };