class Solution {
    public:
      int findKRotation(vector<int> &nums) {
              int mini=INT_MAX;
              int index=-1;
              int low=0,high=nums.size()-1;
              while(low<=high)
              {   int mid=(low+high)/2;
                   // if you want to optimize then this condition not necessary
                   // agar poora array sorted ho gaya ho to compare karke break kardo
                   if(nums[low]<=nums[high]) // mean whole array become sort
                   {  
                       if(nums[low]<mini)
                       {
                           mini=nums[low];
                           index=low;
                           break;
                       }
                   }
                  if(nums[low]<=nums[mid])
                  {
                      if(nums[low]<mini)
                       {
                           mini=nums[low];
                           index=low;
                       }
                      //sorted left mein se min utha liya isliy right half mein dhoondo
                      low=mid+1;
                  }
                  else
                  {
                      if(nums[mid]<mini)
                       {
                           mini=nums[mid];
                           index=mid;
                       }
                      //sorted right se min utha liya isliye left half mein dhoondo
                      high=mid-1;
                  }
              }
              return index;
      }
  };