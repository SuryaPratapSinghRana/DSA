class Solution {
    public:
      int upperbound(vector<int>arr,int elem)
      {   
          int n=arr.size();
          int low=0,high=n-1;
          int ans=n;
          while(low<=high)
          {
              int mid=(low+high)/2;
              if(arr[mid]<=elem)
              {
                  low=mid+1;
              }
              else
              {
                  ans=mid;
                  high=mid-1;
                  
              }
          }
          return ans;
      }
      int countgreEq(vector<vector<int>> &mat,int elem)
      { 
          int n=mat.size();
          int m=mat[0].size();
          int total=0;
          for(int i=0;i<n;i++)
          {
              total+=upperbound(mat[i],elem);
          }
          return total;
      }
      int median(vector<vector<int>> &mat) {
          // code here
          int n=mat.size();
          int m=mat[0].size();
          int reqelem=(n*m)/2;
           int low=INT_MAX,high=INT_MIN;
           for(int i=0;i<n;i++)
           {
               low=min(low,mat[i][0]);
               high=max(high,mat[i][m-1]);
           }
           while(low<=high)
           {
               int mid=(low+high)/2;
               int count=countgreEq(mat,mid);
               if(count<=reqelem)
                 low=mid+1;
               else
                high=mid-1;
           }
           return low;
      }
  };