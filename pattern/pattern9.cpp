#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int i=1;  
    while(i<=n){
   int count=1;                                                                                         
        
    int j=1;
        while(j<=i){
            cout<<i-count+1<<" ";
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
     return 0;
}