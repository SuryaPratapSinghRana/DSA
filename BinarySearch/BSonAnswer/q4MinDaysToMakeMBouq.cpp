class Solution {
    public:
        bool possible(vector<int>&arr,int minday,int m,int k)
        {
            int count=0,totalbouq=0;
            for(int i=0;i<arr.size();i++)
            {
                if(minday>=arr[i])
                  count++;
                else
                {
                    totalbouq+=(count/k);
                    count=0;
                }
            }
            totalbouq+=(count/k);
            if(totalbouq>=m)
              return true;
            else
               return false;
        }
        int minDays(vector<int>& arr, int m, int k) {
            int n=arr.size();
            if(n<(long long)m*k) return -1;
            int mini=INT_MAX,maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<mini)
                  mini=arr[i];
                if(arr[i]>maxi)
                  maxi=arr[i];
            }
            int low=mini,high=maxi;
            int ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(possible(arr,mid,m,k))
                {
                    ans=mid;
                    high=mid-1;  // left half mein dhoondo isse min
                }
                else
                {
                    low=mid+1;  // right half mien dhoondo agar nhi mila
                }
            }
            return ans;
        }
    };