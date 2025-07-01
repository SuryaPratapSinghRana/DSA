#include<iostream>
using namespace std;
class node{
    public:
int data;
node* next;
node* prev;
// constructor
node(int d){
 this->data=d;
 this->next=NULL;
 this->prev=NULL;
}
// destructor 
~node()
{
    int value=this->data;
    cout<<" \n the memory is free for "<<data<<endl;
}
};
// traversing in linked list
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// length of linked list
int getlength(node* &head){
    int length=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}
void insertathead(node* &head,node* &tail,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
         return;
    }
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertattail(node* &head,node* &tail,int d){
     if(tail==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    
}
void insertatposition(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertathead(head,tail,d);
        return;
    }
    node* temp=head;
    for(int i=1;i<pos-1;i++)
    {
      temp=temp->next;
    }
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
    node* middle=new node(d);
    middle->next=temp->next;
    temp->next->prev=middle;
   temp->next=middle;
   middle->prev=temp;
   
}
void deletnode(node* &head,node* &tail,int pos){
    if(pos==1){
        node* curr=head;
        curr->next->prev=NULL;
        head=head->next;
        curr->next=NULL;
        
        delete curr;
        return;
    }
    node* curr=head;
    node* previous=NULL;
    for(int i=1;i<pos;i++)
    {
       previous=curr;
        curr=curr->next;
    }
    if(curr->next==NULL)
    {  tail=previous;
       previous->next=curr->next;
        curr->prev=NULL;
        delete curr;
        return;
    }
    previous->next=curr->next;
   curr->next->prev=previous;
    curr->prev=NULL;
    curr->next=NULL;
    delete curr;
}
int main(){
    /* 
    node* node1=new node(10);
    ----agar hum suru ki node bhi insert func ki help se kraye to isliye comment kra h---
    */
    node* head=NULL;
    node* tail=NULL;
    print(head);
    int length=getlength(head);
    cout<<"the length is "<<length<<endl;
    insertathead(head,tail,11);
     print(head);
      insertathead(head,tail,3);
      insertathead(head,tail,9);
     print(head);
      insertattail(head,tail,6);
      print(head);
      insertatposition(head,tail,5,45);
       print(head);
       deletnode(head,tail,1);
       print(head);
       cout<<" the head is "<<head->data;

    return 0;
}