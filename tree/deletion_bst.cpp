#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node{
int data;
struct node* right,*left;
};
typedef struct node node;
node* insertatbst(node* root,int d)
{   // basecase
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->left=NULL;
        root->right=NULL;
        root->data=d;
        return root;
    }
    if(d>root->data)
    {
     root->right=insertatbst(root->right,d);
    }
    else{
        root->left=insertatbst(root->left,d);
    }
    return root;
}
void takeinput(node** root){
int d;
cin>>d;
while(d!=-1)
{
    *root=insertatbst(*root,d);
    cin>>d;
}
}
void levelordertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
              cout<<temp->data<<" ";
              if(temp->left!=NULL)
              {
                q.push(temp->left);

              }
              if(temp->right!=NULL)
              {
                q.push(temp->right);
              }
        }
    }

}
int min_val(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int max_val(node*root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
node* deletion(node* root,int d)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==d)
    {  
        // 0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left!=NULL && root->right==NULL)
        {
           node* temp=root->left;
           delete root;
           return temp;
        }
        // 1 child
        if(root->left==NULL && root->right!=NULL)
        {
           node* temp=root->right;
           delete root;
           return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            int min=min_val(root->right);
            root->data=min;
            root->right=deletion(root->right,min);
            return root;
        }
        
    }
    else if(root->data>d)
    {   // left part mein jao
        root->left=deletion(root->left,d);
        return root;
    }
    else{
        // right part mein jao
        root->right=deletion(root->right,d);
        return root;
    }
  
}
int main()
{
    node* root=NULL;
    cout<<" enter the data "<<endl;
    takeinput(&root);
   levelordertraversal(root);
   // cout<<endl<<" minimun value "<<min_val(root);
    //cout<<endl<<" maximum value "<<max_val(root);
    root=deletion(root,3);
    levelordertraversal(root);
    return 0;
}
