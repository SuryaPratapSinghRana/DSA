// INSERT AT HEAD OR BEGNING
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
    head=temp; // 
     
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
 cout<<node1->data<<endl;
 cout<<node1->next<<endl;
 //head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,15);
print(head);
    return 0;
}