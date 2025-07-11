#include <bits/stdc++.h> 
void addsoln(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
   vector<int> temp;
  for(int i=0;i<n;i++)
  {
	  for(int j=0;j<n;j++)
	  {
		  temp.push_back(board[i][j]);
	  }
  }	
  ans.push_back(temp);
}
bool issafe(int row,int col,vector<vector<int>> &board,int n)
{
	int x=row;
	int y=col;
	// check for same row
	while(y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		y--;
	}
	x=row;
	y=col;
	// check for diagonal
	while(x>=0 && y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		y--;
		x--;
	}
	// check for diagonal
	x=row;
	y=col;
	while(x<n && y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		y--;
		x++;
	}
	return true;
}
void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
if(col==n){
	addsoln(board,ans,n);
	return;
}	
// solve case 1 rest recursion will handle
for(int row=0;row<n;row++)
{
        if(issafe(row, col, board, n)){
                        // if placing colm is safe
                        board[row][col] = 1;
                        solve(col + 1, ans, board, n);
						//backtrack
                        board[row][col] = 0;
        }
}
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;
	solve(0,ans,board,n);
	return ans;
}