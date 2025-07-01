#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int sumofd(vector<int>&arr,int &div)
        {
            int sum=0;
            for(int i=0;i<arr.size();i++)
            {
                sum+=ceil(arr[i]*1.0/div);
            }
            return sum;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int maxi=INT_MIN;
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                maxi=max(maxi,nums[i]);
            }
            int low=1,high=maxi,ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(sumofd(nums,mid)<=threshold)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return ans;
        }
    };