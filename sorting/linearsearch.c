#include<stdio.h>
int main(){
    int n,i;
    bool key=false;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n-1;i++){
        scanf("%d",&arr[i]);
    }
        int search;
    scanf("%d",&search);
    for(i=0;i<n-1;i++){
        if(arr[i]==search)
        key=true;
        
    }
    return 0;
}