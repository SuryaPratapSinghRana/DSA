class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=arr.size();
        if(n==0){
            return {newInterval};
        }
        for(int i=0;i<n;i++){
            // left non-overlapping  interval
            while(i<n && arr[i][1]<newInterval[0]){
                   ans.push_back({arr[i][0],arr[i][1]});
                   i++;
            }
            //overlapping interval 
            while(i<n && arr[i][0]<=newInterval[1]){
                   newInterval[0]=min(arr[i][0],newInterval[0]);
                   newInterval[1]=max(arr[i][1],newInterval[1]);
                   i++;
            }
            ans.push_back({newInterval[0],newInterval[1]});
            // rigth non-overlaping interval
            while(i<n)
            {
                ans.push_back({arr[i][0],arr[i][1]});
                i++;
            }
        }
        return ans;
    }
};