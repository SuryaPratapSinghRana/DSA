// by traversing list and data replace is allow
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
void sort012(node* &head)
{
    int zeroes=0,ones=0,two=0;
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        zeroes++;
        else if(temp->data==1)
        ones++;
        else
        two++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(zeroes!=0){
        temp->data=0;
        zeroes--;
        }
        else if(ones!=0)
        {
        temp->data=1;
             ones--;
        }
        else if(two!=0){
        temp->data=2;
        two--;
        }
        temp=temp->next;

    }


}
int main(){
node *node1=new node(1); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,2);
insertathead(head,0);
insertathead(head,1);
insertathead(head,0);
print(head);
sort012(head);
print(head);
    return 0;
}