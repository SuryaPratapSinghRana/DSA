class Solution {
public:
   int bfs(int n,vector<vector<int>>&board)
   {
    vector<vector<int>>vis(n,vector<int>(n,0));
    vis[n-1][0]=1;
    queue<int>q;
    q.push(1);
    int step=0;
    while(!q.empty())
    {   
      int N=q.size();
      while(N--)
      {
        int u=q.front();
        q.pop();
        if(u==n*n)
          return step;

        for(int i=1;i<=6;i++)
        {
            int num=u+i;
            if(num>n*n)
            {
               break;
            }
            int row=(n-1)-(num-1)/n;
            int col=(num-1)%n;
            if((n%2==0 && row%2==0) || (n%2==1 && row%2==1))   // agar right to left h ye wala colm
            {
                col=n-1-col;
            }
            if(vis[row][col]==1)
            {
                continue;
            }
            vis[row][col]=1;
            if(board[row][col]==-1)
              q.push(num);
            else
             q.push(board[row][col]);
        }
      }
      step++;
    }
    return -1;
    
   }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        return bfs(n,board);
    }
};