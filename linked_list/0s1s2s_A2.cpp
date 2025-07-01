// sort 0s 1s and 2s
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
void insertattail(node* &tail,node* curr)
{ 
    tail->next=curr;
    tail=curr;
}
node* sortlist(node* head)
{
    node* zerohead=new node(-1);
    node* zerotail=zerohead;
    node* onehead=new node(-1);
    node* onetail=onehead;
    node* twohead=new node(-1);
    node* twotail=twohead;
    node* curr=head;
    // create three seprate list
    while(curr!=NULL)
    {
        int value=curr->data;
        if(value==0){
            insertattail(zerotail,curr);
        }
        else if(value==1)
        {
            insertattail(onetail,curr);
        }
        else if(value==2)
        {
            insertattail(twotail,curr);
        }
        curr=curr->next;

    }
    // merge three sublist
    if(onehead->next!=NULL)
    {
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    // setup head
    head=zerohead->next;
    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}
int main(){
node *node1=new node(1); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,2);
insertathead(head,1);
insertathead(head,0);
insertathead(head,0);
insertathead(head,1);
print(head);
head=sortlist(head);
print(head);

    return 0;
}