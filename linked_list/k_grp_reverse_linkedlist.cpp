// k group reverse
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
node* kreverse(node* head,int k){
    // base call
    if(head==NULL){
        return NULL;
    }
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    int count=0;
    // reverse k nodes
    while(curr!=NULL && count<k)
    { forward=curr->next;
      curr->next=prev;
      prev=curr;
     curr=forward;
      count++;
    }
    // recurive call
    if(forward!=NULL)
    {
    head->next=kreverse(curr,k);
    }
    // return head of previos list
    return prev;
}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,15);
insertathead(head,7);
insertathead(head,12);
print(head);
head=kreverse(head,2);
print(head);
    return 0;
}