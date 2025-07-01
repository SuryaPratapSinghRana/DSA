// binary search Approach

#include<bits/stdc++.h>
class Solution {
  public:
  int reqstation(vector<int> &stations, double dist)
  {
      int count=0;
      for(int i=1;i<stations.size();i++)
      {
          int gap=stations[i]-stations[i-1];
          int stationbetween=gap/dist;
          count+=stationbetween;
          if(stationbetween*dist==gap) // agar manlo 1 ka gap h agar 0.5 banan ho to 1 req to 1/0.5=2  lekin 2 station nhi ek chahiye matlab jab bhi gap poora divide hojae to decreament karo  
          {
              count--;
          }
      }
      return count;
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low=0,high=-1;
        for(int i=1;i<stations.size();i++)
        {
            high=max(high,double(stations[i]-stations[i-1]));
        }
        double ans=-1;
        while(high-low>1e-7)
        {
            double mid=(low+high)/2;
            int stationReq=reqstation(stations,mid);
            if(stationReq>k)
            {
                low=mid;
            }
            else
            {
                high=mid;
                ans=mid;
            }
        }
        
        return high;
    }
};

//using priority queue

class Solution {
    public:
      double findSmallestMaxDist(vector<int> &stations, int k) {
          // Code here
          
          int n = stations.size();
          vector<int>howManyInserted(n-1, 0);
          priority_queue<pair<double, int>>pq;
          
          for(int i=0; i<n-1; i++){
              pq.push({stations[i+1]-stations[i], i});
          }
          
          for( int gasStation = 1; gasStation <=k; gasStation++){
                auto tp = pq.top(); pq.pop();
                int sectionIndex = tp.second;
                howManyInserted[sectionIndex]++;
          
                 double diff = (stations[sectionIndex+1] - stations[sectionIndex]);
                 double newSection = diff / (double)(howManyInserted[sectionIndex]+1);
          
                pq.push({newSection, sectionIndex});
          }
          
                return round(100*pq.top().first)/100; // for gfg round of upto two decimal answer
      }
  };

  //brute force

  class Solution {
    public:
      double findSmallestMaxDist(vector<int> &stations, int k) {
          // Code here
          vector<int>howManyInserted(stations.size()-1,0);
          for(int i=0;i<k;i++)
          {
              int maxindex=-1;
              double maxi=-1;
              for(int j=0;j<stations.size()-1;j++)
              {
                  if(maxi<((stations[j+1]-stations[j])/(howManyInserted[j]+1)))
                  {
                      maxi=(stations[j+1]-stations[j])/((double)howManyInserted[j]+1);
                      maxindex=j;
                  }
              }
              howManyInserted[maxindex]++;

          }
          double ans=-1;
          for(int j=0;j<stations.size()-1;j++)
              {
                  if(ans<((stations[j+1]-stations[j])/(howManyInserted[j]+1)))
                  {
                      ans=(stations[j+1]-stations[j])/((double)howManyInserted[j]+1);
                  }
              }
        return ans;
      }
  };