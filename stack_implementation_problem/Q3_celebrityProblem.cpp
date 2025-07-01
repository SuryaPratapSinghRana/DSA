class Solution {
    public:
      // Function to find if there is a celebrity in the party or not.
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int top=0;
          int down=mat.size()-1;
          while(top<down)
          {
              if(mat[top][down]==1)
                top++;
              else if(mat[down][top]==1)
                down--;
              else
               {
                   top++;
                   down--;
               }
          }
          if(top>down)
             return -1;
          //now check vertical and horizontal for top/down elemnt if he can be celebrity
          for(int i=0;i<mat.size();i++)
          {
              if(i!=top)
              {
                  if(mat[top][i]==0 && mat[i][top]==1)
                  {
                      
                  }
                  else
                  {
                      return -1;
                  }
              }
          }
          return top;
      }
  };