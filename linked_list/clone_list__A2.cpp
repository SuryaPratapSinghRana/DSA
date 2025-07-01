// CLONE 2 LIST WITH RANDOM POINTER
#include<iostream>
#include<map>
using namespace std;
class node{
public:
int data;
node *next;
node *random;
node(int data){
    this->data=data;
    this->next=NULL;
    this->random=NULL;
}


};
void insertathead(node* &head,int d){
    // new node
    node *temp=new node(d);
    temp->next=head;
    temp->random=temp;
    head=temp; 
}
void inserattail(node* &head,node* &tail,int d)
{ node* temp=new node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;

}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        //cout<<temp->random->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* copylist(node* head)
{
    // step1 create a clone list
    node* clonehead=NULL;
    node* clonetail=NULL;
    node* temp=head;
    while(temp!=NULL)
    {
        inserattail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    // step 2 create a map
    map<node*,node*> oldtonew;
    node* temp1=head;
    node* temp2=clonehead;
    while(temp1!=NULL && temp2!=NULL)
    {
        oldtonew[temp1]=temp2;
        temp1=temp1->next;
        temp2=temp2->next;

    }
    temp1=head;
    temp2=clonehead;
    while(temp1!=NULL)
{ 
    temp2->random=oldtonew[temp1->random];
    temp2=temp2->next;
    temp1=temp1->next;

}
return clonehead;
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
node* head2=copylist(head);
print(head2);
    return 0;
}