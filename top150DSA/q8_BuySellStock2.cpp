class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {
                maxprof+=prices[i]-prices[i-1];
            }
        }
        return maxprof;
    }
};

// or local minima and local maxima se bhi kar sakte h