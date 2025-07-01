#include<stdio.h>
int stair(int n){
if(n<0)
return 0;
if(n==0)
return 1;
return stair(n-1)+stair(n-2);
}
int main(){
int n;
printf("enter the value of n");
scanf("%d",&n);
int ans=stair(n);
printf("%d",ans);
    return 0;
}