// find middle node
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
int getlength(node* head){
    int len=1;
    while(head->next!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
//  getmiddle function
node* getmiddle(node* head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    // 2 nodes
    if(head->next->next==NULL){
        return head->next;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,15);
insertathead(head,19);
insertathead(head,10);
print(head);
node* middle=getmiddle(head);
cout<<middle->data;
    return 0;
}