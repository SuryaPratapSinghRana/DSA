// check linked list is palindrom or not
#include<iostream>
#include<vector>
using namespace std;
class node{
public:
int data;
node *next;
node(int data){
    this->data=data;
    this->next=NULL;
}


};
void insertathead(node* &head,int d){
    // new node
    node *temp=new node(d);
    temp->next=head;
    head=temp; //  head=head->next  sahi h
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool palindrom(node* head)
{
   vector<int> arr;
    node* temp=head;
    int i=0;
    while(temp!=NULL)
    {  arr.push_back(temp->data);
        temp=temp->next;
      
    }
   int n=arr.size();
   int s=0;
   int e=n-1;
   int val=1;
   while(s<e)
   {
    if(arr[s]!=arr[e])
    {
        val=0;
    }
    s++;
    e--;

   }
    return val;
}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,10);
print(head);
if(palindrom(head)){
    cout<<" linked list is palindrom ";
}
else
cout<<"linked list is not palindrom ";
    return 0;
}