class Solution {
    public:
        int singleNonDuplicate(vector<int>& arr) {
            int n=arr.size();
            if(n==1)
              return arr[0];
            if(arr[0]!=arr[1])
              return arr[0];
            if(arr[n-1]!=arr[n-2])
              return arr[n-1];
            int low=1,high=n-2;
            while(low<=high)
            {
                int mid=(low+high)/2;
                // checking kya ye single element h
                if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
                  return arr[mid];
                // check karo kya aur eleminate karo left half agar waha nhi h .(even,odd) mean in right half single element
                if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid]==arr[mid+1]) )
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;  // else mtlb (odd,even) isliye left half mein jao
                }
    
            }
            return -1;
        }
    };