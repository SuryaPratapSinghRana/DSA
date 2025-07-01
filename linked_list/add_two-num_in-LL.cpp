// add two number in linked list
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
void insertattail(node* &head,node* &tail,int digit)
{
 node* temp=new node(digit);
 if(head==NULL ){
    head=temp;
    tail=temp;
 }
 else{
    tail->next=temp;
    tail=temp;
 }
}
node* add(node* head1,node* head2)
{int carry=0;
node* anshead=NULL;
node* anstail=NULL;
while(head1!=NULL || head2!=NULL || carry!=0 ){
    int val1=0,val2=0;
    if(head1!=NULL)
    val1=head1->data;
    if(head2!=NULL)
    val2=head2->data;
    int sum=carry + val1+val2;
    int digit=sum%10;
    // create node and add in answer linked list
    insertattail(anshead,anstail,digit);
    carry=sum/10;
    if(head1!=NULL)
    head1=head1->next;
    if(head2!=NULL)
    head2=head2->next;
}
return anshead;
}

node* sumLL(node* head1,node* head2)
{
    // step 1 reverse input linked list
    head1=reverse(head1);
    head2=reverse(head2);
    // step 2 add two linked list
    node* ans=add(head1,head2);
    // step 3 ans wali list ko reverse krdo
    ans=reverse(ans);
     return ans;
}

int main(){
node *node1=new node(8); 
node *node2=new node(3);// ye humne pointer object banaya aur yehi pe contructor ko perimeter dediya
cout<<node1->data<<endl;
cout<<node1->next<<endl;
// head pointed node 1
node *head1=node1;
node* head2=node2;
insertathead(head2,6);
insertathead(head2,3);
insertathead(head1,2);
insertathead(head1,5);
print(head1);
print(head2);
node* addll=sumLL(head1,head2);
print(addll);
    return 0;
}