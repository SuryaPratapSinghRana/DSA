class Solution {
    public:
        double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
            int n1=arr1.size();
            int n2=arr2.size();
            if(n1>n2)return findMedianSortedArrays(arr2,arr1); // pehle wala chhota array banao swap krke agar nhi h
            int low=0,high=n1;
            int left=(n1+n2+1)/2;
            int n=n1+n2;
            // jitni mid1 ki value utne left mein elemnt of arr1 and arr1[mid1] is r1 and arr1[mid1-1] represent l1
            // jitni mid2 ki value utne left mein elemnt of arr2 and arr2[mid1] is r2 and arr2[mid2-1] represent l2
            while(low<=high)
            {
                int mid1=(low+high)/2;
                int mid2=left-mid1;
                int r1=INT_MAX,r2=INT_MAX;
                int l1=INT_MIN,l2=INT_MIN;
                if(mid1-1>=0)l1=arr1[mid1-1];
                if(mid2-1>=0)l2=arr2[mid2-1];
                if(mid1<n1)r1=arr1[mid1]; // agar right mein kuch hoga tabhi lenge na r1 isliye if condition
                if(mid2<n2)r2=arr2[mid2]; // agar right mein kuch hoga tabhi lenge na r2 isliye if condition
                if(l1<=r2 && l2<=r1)
                {
                    if(n%2==1) return max(l1,l2);
                    return (double)((double)max(l1,l2)+(double)min(r1,r2))/2.0;
                }
                else if(l1>r2)
                {
                  high=mid1-1; // left half mein element kam karo jab high=mid1-1 karenge to mid1 bhi ghatega
                }
                else
                {
                    low=mid1+1;
                }
            }
            return 0;
    
        }
    };