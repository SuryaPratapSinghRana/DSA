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
//  findmiddle function
node* findmiddle(node* head)
{
    int len=getlength(head);
    int ans=len/2+1; // yha pe ek position kam liya h
    node* temp=head;
    int count=1;
    while(count<ans){
     temp=temp->next;
     count++;
    }
    return temp;

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
node* middle=findmiddle(head);
cout<<middle->data;
    return 0;
}