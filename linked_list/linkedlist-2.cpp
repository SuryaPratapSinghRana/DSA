// INSERT AT TAIL OR END
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
void insertattail(node* &tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp; //  tail=tail->next bhi sahi h
    
}
void print(node* &node1){
    node *temp=node1;
    while(temp!=NULL){
   cout<<temp->data<<" ";
   temp=temp->next;
}
}
int main(){
node *node1=new node(10);
node *tail=node1;
insertattail(tail,12);
print(node1);
    return 0;
}