#include<iostream>
 using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int space;
    int i=1;  
    while(i<=n){ 
        space=n-i;
    int j=1; 
        while(space){
            cout<<" ";
            space--;
        
        }
        while(j<=i)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
     return 0;
}
