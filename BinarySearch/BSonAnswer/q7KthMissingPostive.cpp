#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int countmissing=arr[mid]-mid-1;
            if(countmissing<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    } 
    return high+k+1;
  }  // iska derivation notebook mein dekho
    };
