// MERGE SORT IN LINKED LIST
#include<iostream>
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
node* findmid(node* head)
{
    node* fast=head->next;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

    }
    return slow;
}
node* merge(node* left,node* right)
{
if(left==NULL){
    return right;
}
if(right==NULL)
{
    return left;
}
node* ans=new node(-1);
node* temp=ans;
// merge 2 sorted linked list
while(left!=NULL && right!=NULL)
{
    if(left->data < right->data){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    else{
        temp->next=right;
        temp=right;
        right=right->next;
    }
}
while(left!=NULL)
{ 
    temp->next=left;
    temp=left;
    left=left->next;
} 
while(right!=NULL)
{
    temp->next=right;
    temp=right;
    right=right->next;
   
}
ans=ans->next;
    
return ans;
}
node* mergesort(node* head)
{  // base case
  if((head->next==NULL) || head==NULL)
  {
    return head;
  }
  // break linked list in 2 half,after finding mid
  node* mid=findmid(head);
  node* left=head;
  node* right=mid->next;
  mid->next=NULL;
  // recursive call to sort both half
  left=mergesort(left);
  right=mergesort(right);
  // merge both left and right half

  node* result=merge(left,right);

  return result;

}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,15);
print(head);

head=mergesort(head);
print(head);
    return 0;
}