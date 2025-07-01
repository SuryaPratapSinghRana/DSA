#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int i=1;  
   char ch='A';                                                                                         
    while(i<=n){
    int j=1;
        while(j<=n){
            // ya phir char ch='A'+i-1 to phir ch ko ch++ nhi krana pdega
            cout<<ch<<" ";
            j++;
        }
            ch++;
        cout<<endl;
        i++;
    }
     return 0;
}