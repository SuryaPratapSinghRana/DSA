class Solution {
    public:
        double timetoeat(vector<int>&arr,int hourly)
        {
            double tothrs=0;
            for(int i=0;i<arr.size();i++)
            {
                tothrs+=ceil(1.0*arr[i]/hourly);
            }
            return tothrs;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxi=INT_MIN;
            for(int i=0;i<piles.size();i++)
            {
                maxi=max(piles[i],maxi);
            }
            int low=1,high=maxi;
            int ans=INT_MAX;
            while(low<=high)
            {
                int mid=(low+high)/2;
                double hourstake=timetoeat(piles,mid);
                if(hourstake<=h)
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