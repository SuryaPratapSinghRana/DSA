int knap(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0){
           if(W>=wt[0])
           {
               return val[0];
           }
           return 0;
       }
       int not_take=knap(W,wt,val,n-1);
       int take=INT_MIN;
       if(wt[n]<=W)
       {
           take=val[n]+knap(W-wt[n],wt,val,n-1);
       }
       return max(not_take,take);
       
    }