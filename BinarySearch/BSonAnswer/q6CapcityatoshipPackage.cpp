class Solution {
    public:
    bool possible(vector<int>& arr, int cap, int days) {
        int tempcap = cap;
        int daystaken = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > cap) return false; // sanity check (not strictly needed due to low=maxi)
            if (tempcap < arr[i]) {
                daystaken++;
                tempcap = cap;
            }
            tempcap -= arr[i];
        }
        return daystaken <= days;
    }
    
        int shipWithinDays(vector<int>& weights, int days) {
            int maxi=INT_MIN;
            int sum=0;
            for(int i=0;i<weights.size();i++)
            {
                maxi=max(maxi,weights[i]);
                sum+=weights[i];
            }
            int low=maxi,high=sum,ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(possible(weights,mid,days))
                {
                    ans=mid;
                    high=mid-1;  // left half mein jao smaller answer dhoondo
                }
                else
                {
                    low=mid+1;   // right mein jao possible anser dhoondo
                }
            }
            return ans;
        }
    };