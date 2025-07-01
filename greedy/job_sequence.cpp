struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
   static bool cmp(Job a,Job b){
    return a.profit>b.profit;
   }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int maxdeadline=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i].dead>maxdeadline){
                maxdeadline=arr[i].dead;
            }
        }
        vector<int> v(maxdeadline+1,-1);
       int profit=0,count=0;
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            while(j>0)
            {
                if(v[j]==-1){
                    v[j]=arr[i].id;
                    profit=profit+arr[i].profit;
                    count++;
                    break;
                }
                else
                j--;
            }
        }
        vector<int> ans;
        ans.push_back(count);
         ans.push_back(profit);
         return ans;
    } 
};