 class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int j = 0,i=0 ;
        int curr = 0 ;
        int minSize = INT_MAX; 
        while(i<v.size())
        {  
            curr += v[i] ; 
            i++;
               while(curr>=target)
                {
                    minSize=min(minSize,i-j);
                    curr-=v[j];
                    j++;
                }
        }
        return (minSize != INT_MAX) ? minSize : 0;
    }
};