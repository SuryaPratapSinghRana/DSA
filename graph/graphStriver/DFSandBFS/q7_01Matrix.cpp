
// hum same rotten orange ki trah bhi kar sakte time ko pair ke andar leke h phir hume level wise nhi chalna padega
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            vector<vector<int>>vis(n,vector<int>(m,-1));
            queue<pair<int,int>>q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]==0)
                    {
                        q.push({i,j});
                        vis[i][j]=0;
                    }
                }
            }
            int level=1;
            while(!q.empty())
            {
               int size=q.size();
               while(size--)
               {
                 auto front=q.front();
                 q.pop();
                 int row=front.first;
                 int colm=front.second;
                 int delrow[]={0,-1,0,1};
               int delcolm[]={-1,0,1,0};
               for(int i=0;i<4;i++)
               {
                  int irow=delrow[i]+row;
                  int icolm=delcolm[i]+colm;
                  if(irow>=0 && irow<n && icolm<m && icolm>=0 && vis[irow][icolm]==-1) 
                    {
                          q.push({irow,icolm});
                      vis[irow][icolm]=level;
                       
                    }  
                  
               }
               }
               level++;
            }
            return vis;
    
        }
    };