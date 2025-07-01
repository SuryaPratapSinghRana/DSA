class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            
           priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            int n=heights.size();
            int m=heights[0].size();
            pq.push({0,{0,0}});
            vector<vector<int>>dist(n,vector<int>(m,1e8));
            vector<int> drow = {0,1,-1,0,1,-1,1,-1};
            vector<int> dcol = {1,0,0,-1,1,1,-1,-1};
            dist[0][0]=0;
            while(!pq.empty())
            {
                auto front=pq.top();
                pq.pop();
                int diff=front.first;
                int row=front.second.first;
                int col=front.second.second;
                if(row==n-1 && col==m-1)
                  return diff;
                for(int i=0;i<4;i++)
                {
                    int irow=row+drow[i];
                    int icol=col+dcol[i];
                    if(irow>=0 && irow<n && icol>=0 && icol<m)
                    {
                        int newEffort=max(abs(heights[row][col]-heights[irow][icol]),diff);
                        if(newEffort<dist[irow][icol])
                        {
                            dist[irow][icol]=newEffort;
                            pq.push({newEffort,{irow,icol}});
                        }
                    }
                }
    
            }
            return dist[n-1][m-1];
        }
    };