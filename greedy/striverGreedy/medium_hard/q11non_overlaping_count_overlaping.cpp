class Solution {
public:
   static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int>prevtaken=intervals[0];
        int count=0;
        for(int i=1;i<n;i++){
            if(prevtaken[1]>intervals[i][0])
            {
                count++;
            }
            else
            {
                prevtaken=intervals[i];
            }
        }
        return count;
    }
};