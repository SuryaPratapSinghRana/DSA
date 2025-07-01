#include<iostream>
using namespace std;
int main(){
int n;
char ch='A';
cin>>n;
int i=1;
while(i<=n){
    int j=1;
while(j<=n){
    if(i%2!=0){
    cout<<ch<<" ";
    ch++;
    j++;}
    else{
    cout<<ch<<" ";
    ch--;
    j++;}
    
}
cout<<endl;
    if(i%2==0)
    ch=ch+2;
    else
    ch=ch-1;
    i++;
}
    return 0;
}