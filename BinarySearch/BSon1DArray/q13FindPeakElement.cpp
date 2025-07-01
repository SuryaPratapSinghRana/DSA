class Solution {
    public:
        int findPeakElement(vector<int>& arr) {
            int n=arr.size();
            if(n==1) return 0;
            if(arr[0]>arr[1])
               return 0;
            if(arr[n-1]>arr[n-2])
               return n-1;
            int low=1,high=n-2;  // kyunki 0 and n-1 ka case bahar handle kar liya
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                // check if it is peak return it
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                  return mid;
                  // increasing slope so go to right if increasing
                else if(arr[mid]>arr[mid-1])
                  low=mid+1;
                // decreasing slope so go to left if decresing
                else if(arr[mid]>arr[mid+1])
                  high=mid-1;
                else
                  low=mid+1; // chahe to high=mid-1 likh do fark nhi padega dono side peak h is dip ke case mein             
            }
            return -1;  // dummy
        }
    };