#include <bits/stdc++.h> 
int func(int i,int j1,int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{   
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
       return -1e8;
    if(i==grid.size()-1){
        if(j1==j2)
          return grid[i][j1];
        else
         return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
      return dp[i][j1][j2];

   int maxi=-1e8;
   
   // 9 combination between alice(j1)  & bob(j2) when going down
   for(int delj1=-1;delj1<=1;delj1++){
       for(int delj2=-1;delj2<=1;delj2++)
       {
           if(j1==j2){
               maxi=max(maxi,grid[i][j1]+func(i+1,j1+delj1,j2+delj2,grid,dp));
           }
           else
           {
               maxi=max(maxi,grid[i][j2]+grid[i][j1]+func(i+1,j1+delj1,j2+delj2,grid,dp));
           }
       }
   }

   return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    int m = r, n = c;
vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

 return func(0,0,n-1,grid,dp);

}