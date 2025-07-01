#include<iostream>
#include<vector>
using namespace std;
void printseq(int index,vector<int> &ans,int arr[],int n)
{
    if(index==n)
    {
        for(auto it:ans){
            cout<<it<<" ";
        }
        if(ans.size()==0){  // ye condition null print krne ke liye h
         cout<<"{}";
        }
        cout<<endl;
        return;
    }
    // take or pick particular index into subsequence
    ans.push_back(arr[index]);
    printseq(index+1,ans,arr,n);
    ans.pop_back();
    // not take or not pick particular index into subsequence
    printseq(index+1,ans,arr,n);
}
int main(){
int arr[]={3,1,2};
vector<int> ans;
int n=3;
printseq(0,ans,arr,n);
    return 0;
}