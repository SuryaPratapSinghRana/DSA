class Solution {
    public:
        void dfs(vector<vector<int>>& ans,int row,int colm,int color,int &startcolor)
        {
           ans[row][colm]=color;
           int n=ans.size();
           int m=ans[0].size();
           int delrow[]={0,-1,0,1};
           int delcolm[]={-1,0,1,0};
           for(int i=0;i<4;i++)
           {
              int irow=delrow[i]+row;
              int icolm=delcolm[i]+colm;
              if(irow>=0 && irow<n && icolm<m && icolm>=0 && ans[irow][icolm]==startcolor) 
                dfs(ans,irow,icolm,color,startcolor);
              
           }
    
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int n=image.size();
            int m=image[0].size();
            int startcolor=image[sr][sc];
            vector<vector<int>>ans(n,vector<int>(m,-1));
            // ye base case jarur lgao warna infinte recursion mein fase ga jab bhi jo
            if(color==startcolor)
              return image;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                        ans[i][j]=image[i][j];
                }
            }
            dfs(ans,sr,sc,color,startcolor);
      
            return ans;
        }
        };
    