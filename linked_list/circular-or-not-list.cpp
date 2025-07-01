#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        cout<<" the memory is free for "<<val<<endl;
    }
};
void insertnode(node* &tail,int element,int d){
   
    // empty list
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
      // non empty list  
       // asuming that the element is present in the list
    node* curr=tail;
    while(curr->data!=element){
        curr=curr->next;
    }
    // element is found and current is representing that element
      node* temp=new node(d);
      temp->next=curr->next;
      curr->next=temp;
    }
}
void print(node* tail){
    node* temp=tail;
        if(tail==NULL){
            cout<<" list is empty "<<endl;
          return;
        }
    // single node ke hisab se hum ise print nhi kra sakte isliye pehle hi krna padega 
    // do-while loop bhi chla sakte h
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    } while(tail!=temp);
    cout<<endl;
}
void deletnode(node* &tail,int value){
    // empty list
  if(tail==NULL){
    cout<<" the linked list is empty"<<endl;
    return;
  }
  else{
    // non empty list
    node* prev=tail;
    node* curr=prev->next;
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    // 1 one node linked list
    if(curr==prev){
        tail=NULL;
    }
    // >=2 node linked list
     if(tail==curr){
        tail=prev;
     }
    curr->next=NULL;
    delete curr;
  }
 
}
 bool iscircular(node* head)
  {
    // empty list said to be circular
    if(head==NULL){
        return true;
    }
    // 1 node
    if(head->next==NULL){
        return false;
    }
    // >1 node
    node* temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if(temp==NULL){
        return false;  // means non-circulr
    }
    if(temp==head)
    {
        return true;  // list is circular
    }
    return false;
  }
int main(){
    node* tail=NULL;
    // empty list me insert krre hai
     insertnode(tail,5,3);
     print(tail);
     insertnode(tail,3,6);
     print(tail);
     insertnode(tail,6,4);
     print(tail);
     insertnode(tail,4,7);
     print(tail);
     insertnode(tail,4,9);
    //  print(tail);
    //  deletnode(tail,3);
    //  print(tail);
    if(iscircular(tail)){
        cout<<" \n linked list is circular in nature";
    }
    return 0;
}