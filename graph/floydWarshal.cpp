class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
        // this is if no edge then make infinity
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1)
	            {
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
	    
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][via]+matrix[via][j],matrix[i][j]);
	            }
	        }
	    }
	    
      // if infinity means no edge so make it -1
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)
	            {
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};