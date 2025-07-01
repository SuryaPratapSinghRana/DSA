
class Solution {
    public:
        int noofstudent(vector<int>&nums,int pages)
        {
            int student=1,pagestudent=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]+pagestudent<=pages)
                {
                    pagestudent+=nums[i];
                }
                else
                {
                    student++;
                    pagestudent=nums[i];
                }
            }
            return student;
        }
        int findPages(vector<int>& nums, int k) {
            int low=INT_MIN,high=0;
            for(int i=0;i<nums.size();i++)
            {
                low=max(low,nums[i]);
                high+=nums[i];
            }
            while(low<=high)
            {
                int mid=(low+high)/2;
                int studentallocated=noofstudent(nums,mid);
                if(studentallocated>k)
                 low=mid+1;
                else
                   high=mid-1; 
            }
            return low;
        }
    };