class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minSoFar=prices[0];
       int maxprof=0;
       for(int i= 1;i<prices.size();i++)
       {
        minSoFar=min(minSoFar,prices[i]);
        int profit=prices[i]-minSoFar;
        maxprof=max(maxprof,profit);
       }      
       return maxprof;
    }
};

// or right greatest element array se bhi kar sakte ho