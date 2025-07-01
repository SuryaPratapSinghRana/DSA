class Solution {
    public:
    int lowerbound(vector<int>& nums, int n,int target) {
              int low=0;
              int high=n-1;
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
               return  n-ans; // itne ones h and ans mean first occerenc of 1 index   
          }
      int maxOnes(vector<vector<int>> &mat, int n, int m) {
          // your code here
          int count=0;
          int ans=-1;
          for(int i=0;i<n;i++)
          {
              int count_one=lowerbound(mat[i],m,1);
              if(count_one>count)
              {
                  count=count_one;
                  ans=i;
              }
          }
          return ans;
          
      }
  };