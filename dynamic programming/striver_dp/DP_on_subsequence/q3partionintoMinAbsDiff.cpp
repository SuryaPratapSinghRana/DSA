class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        
        // tabulation lga kr dp table fill karenge by subset sum equal to k logic
        
        int n=arr.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];  
        }
        
        vector<vector<bool>>dp(n,vector<bool>(totalsum+1,false));
        // base case fill
        for(int i=0;i<n;i++)
         {
             dp[i][0]=true; // jab target 0 to true kardo achivable h har index pe
         }
         
         // 0 index pe arr[0] target ahcivable h to true kar do
         dp[0][arr[0]]=true;
         
         for(int i=1;i<n;i++){
             for(int target=0;target<=totalsum;target++){
                 int not_take=dp[i-1][target];
                 int take=false;
                 if(arr[i]<=target){
                     take=dp[i-1][target-arr[i]];
                 }
                 dp[i][target]=take || not_take;
             }
         }
         
         int mini=INT_MAX;
         for(int target1=0;target1<totalsum;target1++){
             if(dp[n-1][target1]==true)
             {
                 int target2=totalsum-target1;
                 mini=min(mini,abs(target1-target2));
             }
         }
         
         return mini;
         
        
    }
};