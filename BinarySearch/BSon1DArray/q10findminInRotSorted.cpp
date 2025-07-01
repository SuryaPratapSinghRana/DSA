class Solution {
    public:
        int findMin(vector<int>& nums) {
            int mini=INT_MAX;
            int low=0,high=nums.size()-1;
            while(low<=high)
            {   int mid=(low+high)/2;
                 // if you want to optimize then this condition not necessary
                 // agar poora array sorted ho gaya ho to compare karke break kardo
                 if(nums[low]<=nums[high]) // mean whole array become sort
                 {
                    mini=min(mini,nums[low]);
                    break;
                 }
                if(nums[low]<=nums[mid])
                {
                    mini=min(nums[low],mini);
                    //sorted left mein se min utha liya isliy right half mein dhoondo
                    low=mid+1;
                }
                else
                {
                    mini=min(nums[mid],mini);
                    //sorted right se min utha liya isliye left half mein dhoondo
                    high=mid-1;
                }
            }
            return mini;
        }
    };