#include<iostream>
 using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    char ch='A';
    int i=1;  
    while(i<=n){ 
    int j=1; 
        while(j<=i){
            cout<<ch<<" ";
            j++;
        }
            ch++;
        cout<<endl;
        i++;
    }
     return 0;
}
