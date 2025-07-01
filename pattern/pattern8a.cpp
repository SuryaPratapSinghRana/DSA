#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int i=1;  
   int count=2;                                                                                         
    while(i<=n){
        
    int j=1;
                int x=i;
        while(j<=i){
            if(i%2!=0){
                cout<<x<<" ";
                x++;
            }
            else{
            cout<<count<<" ";
            count++;
            }
            j++;
        
        }
        cout<<endl;
        i++;
    }
     return 0;
}