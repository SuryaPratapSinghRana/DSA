class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low=0,high=nums.size()-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(nums[mid]==target)
                  return mid;
                // check if left half sorted
                if(nums[low]<=nums[mid])
                {
                    //check if target lie in left half
                    if(nums[low]<= target && nums[mid]>=target)
                    {
                        high=mid-1;
                    }
                    else  // else mean target lie in right half
                    {
                        low=mid+1;
                    }
                }
                else  // else mean right half is sorted
                {
                    //check if target lie in right half
                    if(nums[mid]<= target && nums[high]>=target)
                    {
                        low=mid+1;
                    }
                    else  // else mean target lie in left half
                    {
                        high=mid-1;
                    }
    
                 }
            }
            return -1;
        }
    };