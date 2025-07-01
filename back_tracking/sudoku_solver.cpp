#include <bits/stdc++.h> 
bool issafe(int row,int col,vector<vector<int>> &sudoku,int value)
{
    for(int i=0;i<sudoku.size();i++)
    {
        // check row
        if(sudoku[row][i]==value)
        {
            return false;
        }
        // check colm
        if(sudoku[i][col]==value)
        {
            return false;
        }
        // 3*3 matric check 
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==value){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &sudoku)
{
    int n=sudoku[0].size();
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {     // cell empty
          if(sudoku[row][col]==0){
            for(int val=1;val<=9;val++)
            {
                if(issafe(row,col,sudoku,val))
                {
                    sudoku[row][col]=val;
                    // recursive call
                    bool aagesolnpossible=solve(sudoku);
                    if(aagesolnpossible)
                    {
                        return true;
                    } else {
                        // backtrack
                        sudoku[row][col] = 0;
                    }
                }
            }
            return false;
          }
        }
    }
   return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku);
}