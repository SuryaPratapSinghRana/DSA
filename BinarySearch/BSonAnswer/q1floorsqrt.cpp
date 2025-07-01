class Solution {
    public:
      int floorSqrt(int n) {
          // Your code goes here
          int ans=-1;
          int low=0,high=n;
          while(low<=high){
              int mid=(low+high)/2;
              if(mid*mid==n)
                return mid;
              else if(mid*mid>n)
              {
                  high=mid-1;
              }
              else
              {
                  ans=mid;
                  low=mid+1;
              }
          }
          return ans;
      }
  };