// Remove Duplicate
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
node*  removeduplicate(node* head)
{
    node* curr=head;
    if(head==NULL)
    {
       return NULL;
    }
    while(curr!=NULL)
    {
        if(curr->next!=NULL && curr->data==curr->next->data)
        {
            node* next_next=curr->next->next;
            node* temp=curr->next;
            temp->next=NULL;
            delete temp;
            curr->next=next_next;
        }
        // not equal
        else
        {
            curr=curr->next;
        }
    }
    return head; 
}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,12);
insertathead(head,15);
print(head);
head=removeduplicate(head);
print(head);
    return 0;
}