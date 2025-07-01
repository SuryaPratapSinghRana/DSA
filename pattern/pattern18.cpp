#include<iostream>
 using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int i=1;  
    while(i<=n){ 
int j=1;
// space print karlo
int space=n-i;
        while(space){
            cout<<" ";
            space--;
        }
        // stars print karlo
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
     return 0;
}
