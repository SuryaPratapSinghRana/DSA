// check palindrom without any array
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
node* getmiddle(node* head)
{
    node* fast=head->next;
    node* slow=head;
    while((fast!=NULL) && (fast->next!=NULL))
    { 
        fast=fast->next->next;
        slow=slow->next;
         
    }
    return slow;
}
node* reverse(node* head)
{
    node* curr=head;
    node* prev=NULL;
    node* forw=NULL;
    while(curr!=NULL)
    {
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}
bool palindrom(node* head)
{
    if(head==NULL || head->next==NULL)
    { 
        return true;
         
    }
   
    // step 1 find middle
    node* middle=getmiddle(head);
    // step 2 reverse list after middle
    node* temp=middle->next;
    middle->next=reverse(temp);
      
    // step  3 compare both halves
    node* head1=head;
    node* head2=middle->next;
  
    while(head2 !=NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
         
    }
    // step 4 repeat step 2 to get original linked list
    temp=middle->next;
    middle->next=reverse(temp);
   
    return true;

}
int main(){
node *node1=new node(10); // ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head=node1;
insertathead(head,12);
insertathead(head,10);
print(head);
if(palindrom(head)){
    cout<<" linked list is palindrom ";
}
else
cout<<"linked list is not palindrom ";

    return 0;
}