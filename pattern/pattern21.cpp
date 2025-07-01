#include<iostream>
 using namespace std;
int main(){
    int n;
    cout<<"enter the value of a";
    cin>>n;
    int space=1;
    int i=1;  
    int p=2;
    while(i<=n/2){ 
    int j=1; 
    while(j<=i)
        {
            cout<<"*";
            j++;
        }
        space=1;
        while((space)<=(n-p)){
            cout<<" ";
            space++;
        
        }
        j=1;
        while(j<=i)
        {
            cout<<"*";
            j++;
        }
        p=p+2;
        cout<<endl;
        i++;
    }
     return 0;
}
