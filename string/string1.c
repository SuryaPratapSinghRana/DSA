#include<stdio.h>
int main(){
    char ch[12];
    scanf("%s",&ch);
    int s=0;
//printf("%s",ch);
for(int i=0;ch[i]!='\0';i++){
s=s+1;
}
printf("%d",s);
    return 0;
}