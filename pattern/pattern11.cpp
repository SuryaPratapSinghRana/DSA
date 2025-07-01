#include<iostream>
using namespace std;
int main(){
    int i=1;
    int n;
    cout<<"enter the value of ";
cin>>n;
while(i<=n){
    int j=1;
    char ch='A';
    while(j<=n){
cout<<ch<<" ";
ch++;
j++;
    }
cout<<endl;
i++;
}
    return 0;
}
