class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {
          // code here
          vector<int>dist(100000,1e8);
          queue<pair<int,int>>q; // {step,number}
          dist[start]=0;
          q.push({0,start});
          int mod=100000;
          while(!q.empty())
          {
              auto front=q.front();
              q.pop();
              int u=front.second;
              int step=front.first;
              if(u==end)
                        return step;
              for(auto it:arr)
              {
                  int num=(u*it)%mod;
                  if(step+1<dist[num])
                  {
                      dist[num]=step+1;
                      q.push({step+1,num});
                  }
              }
          }
        return -1;
      }
  };