#include<stdio.h>
int main(){
    char ch[12];
    scanf("%s",&ch);
     int n=0;
//printf("%s",ch);
for(int i=0;ch[i]!='\0';i++){
n=n+1;
}
printf("%d",n);
    for(int i=0;i!=(n-i-1);i++){
int t=ch[i];
ch[i]=ch[n-i-1];
ch[n-1-i]=t;
    }
    //printf("surya");
    printf("%s",ch);
    return 0;
}