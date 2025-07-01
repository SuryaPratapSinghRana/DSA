// CLONE LIST BY  APPROACH THIRD
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
void insertattail(node* &head,node* &tail,int d)
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
    // step 1: create clone list
      node* clonehead=NULL;
      node* clonetail=NULL;
      node* temp=head;
      while(temp!=NULL)
      {
        insertattail(clonehead,clonetail,temp->data);
 
         temp=temp->next;
      }
      
    // step 2: clone list add between original list
         node* originalnode=head;
         node* clonenode=clonehead;
         while(originalnode!=NULL && clonenode!=NULL)
         {
           node* forw1=originalnode->next;
           originalnode->next=clonenode;
           originalnode=forw1;
           node* forw2=clonenode->next;
           clonenode->next=originalnode;
           clonenode=forw2;

         }
    // step 3: random pointer copy karne h
         temp=head;
         while(temp!=NULL)
         {  if(temp->next!=NULL)
         {    if(temp->random!=NULL)
                temp->next->random=temp->random->next;
         }
         else{
            temp->next=temp->random;
         }
         temp=temp->next;
           
         }
    //step 4: revert the changes
      originalnode=head;
      clonenode=clonehead;
      while(originalnode!=NULL && clonenode!=NULL)
      {
        originalnode->next=clonenode->next;
        originalnode=clonenode->next;
        if(originalnode!=NULL)
        {
      clonenode->next=originalnode->next;
        }
        clonenode=originalnode->next;
      }
    // step 5: return the answer
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