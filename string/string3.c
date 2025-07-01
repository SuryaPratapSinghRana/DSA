#include<stdio.h>
int main(){
    char str[20];
    printf("enter the string ");
    scanf("%s",str);
    int s=0;
//printf("%s",ch);
for(int i=0;str[i]!='\0';i++){
s=s+1;
}
int a=s;
int count=0;
for(int i=0;i<s;i++){
    if(str[i]>='a'&& str[i]<='z'){
        str[i]=str[i]-32;
    }
    if(str[s-i-1]>='a'&& str[s-i-1]<='z'){
        str[s-i-1]=str[s-1-i]-32;
    }
}
for(int i=0;i<s;i++){
    // if(((str[i]>='A'&& str[i]<='Z')||(str[i]>='0'&& str[i]<='9'))&&((str[s-i-1]>='A'&& str[s-i-1]<='Z')||(str[s-i-1]>='0'&& str[s-i-1]<='9')))
// if(((str[i]>='A'&& str[i]<='Z')||(str[i]>='0'&& str[i]<='9'))&&((str[s-i-1]>='A'&& str[s-i-1]<='Z')||(str[s-i-1]>='0'&& str[s-i-1]<='9'))){

if(((str[i]<'A'&& str[i]>'Z')||(str[i]<'0'&& str[i]>'9'))&&((str[s-i-1]<'A'&& str[s-i-1]>'Z')||(str[s-i-1]<'0'&& str[s-i-1]>'9'))){
        i++;
       s--;
    
}
   else if(((str[i]>='A'&& str[i]<='Z')||(str[i]>='0'&& str[i]<='9'))&&((str[s-i-1]<'A'&& str[s-i-1]>'Z')||(str[s-i-1]<'0'&& str[s-i-1]>'9'))){
        i++;
       s--;
    
}

// else if((str[s-i-1]>='A'&& str[s-i-1]<='Z')||(str[s-i-1]>='0'&& str[s-i-1]<='9')){
// i++;
// s--;
// }
    else if(str[i]!=str[s-i-1])
count=count+1;


}
if(count!=0)
printf("string is not a palindrom");
else
printf("string is a palindrom");
    return 0;
}