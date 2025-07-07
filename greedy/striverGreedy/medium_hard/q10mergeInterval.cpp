class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        if(n==0)
          return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>previnterval=intervals[0];
        for(int i=0;i<n;i++){
            // overlapping interval
            if(previnterval[1]>=intervals[i][0])
            {
                previnterval[1]=max(previnterval[1],intervals[i][1]);
            }
            else // non-overlaping interval
            {
                ans.push_back(previnterval);
                previnterval=intervals[i];
            }
        }
        ans.push_back(previnterval);
        return ans;
    }
};