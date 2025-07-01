
// detect loop 
#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
       
        }
         ~node(){
            int value=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
           cout<<"memory is free for data "<<value<<endl;
      
            
    }
};
void insertathead(node* &head,int d){
    // new node
    node *temp=new node(d);
    temp->next=head;
    head=temp; 
}
void insertattail(node* &tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp; //  tail=tail->next bhi sahi h
    
}
void insertatmiddle(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertathead(head,d); // jab suru mein dalenge to head update krna padega
        return;
    }
node* temp=head;
for(int i=1;i<pos-1;i++){
temp=temp->next;
}
if(temp->next ==NULL){
    insertattail(tail,d); // jab last mein daalenge to last ko update krna padega
    return;
}
node *middle=new node(d);
middle->next=temp->next;
temp->next=middle;

}
void print(node* &head);
void deletnode(node* &head,node* &tail,int position){
    // deleting first or start node
    if(position==1)
    {  node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete  temp;
       return;
        

    }
    // deleting any middle or last node
    node*curr=head;
    node* prev=NULL;
    for(int i=1;i<position;i++){
        prev=curr;
        curr=curr->next;
    }
    
    if(curr->next==NULL){
        tail=prev;
        prev->next=curr->next; // tail->next=curr->next; ye bhi sahi h kyuki prev and tail dono hi pointer h
        curr->next=NULL;
    delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool detectloop(node* head)
{
    if(head==NULL)
    {
        return false;
    }
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            return 1;  // it means loop present
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false; // it means loop nhi tha tabhi bahar aayi h
}
int main(){
node *node1=new node(10);
node *head=node1;
node *tail=node1;
insertattail(tail,12);
insertattail(tail,34);
insertattail(tail,6);
insertattail(tail,7);
//print(head);
int position;
//cout<<endl<<"enter the position ";
//cin>>position;
insertatmiddle(head,tail,5,4);
print(head);
deletnode(head,tail,6);
print(head);
cout<<"\n tail data is "<<tail->next;
tail->next=head->next;
if(detectloop(head)){
    cout<<"\n loop is present ";
}
else
cout<<" \n loop not present";

    return 0;
}