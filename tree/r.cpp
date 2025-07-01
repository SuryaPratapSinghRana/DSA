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
int searchrecur(node* root,int d)
{   // base case
    if(root==NULL)
    {
       return 0;
    }
    if(root->data==d)
    {
        return 1;
    }
    if(root->data>d)
    {
        return searchrecur(root->left,d);
    }
    else
    {
        return searchrecur(root->right,d);
    }
}
int searchingbyloop(node* root,int d)
{
    while(root!=NULL)
    {
        if(root->data==d)
        {
            return 1;
        }
        if(root->data>d)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}
// a function that will perform the in-order traversal of the bst
void inOrder(node *root, int a[], int i) {
   // checking the base case
   if (root == NULL)
      return;

   // traversing the left subtree
   inOrder(root->left, a, i);

   // inserting the current root's data into the array
   a[i++] = root->data;

   // traversing the right subtree
   inOrder(root->right, a, i);
}

// defining a function that will return the Kth largest element in bst.
int KthLargestElement(node *root, int k, int n) {
   // checking the base case
   if (root == NULL)
      return -1;

   // initializing an array to store the elements of the bst.
   int a[n];

   // calling the helper in-order function
   inOrder(root, a, 0);

   // defining a counter and i which will help us to traverse the array.
   int counter = 0;
   int i = 0;

   // decrementing the counter
   while (counter < k) {
      i = i - 1;
      counter = counter + 1;
   }

   // returning the kth largest element of the bst
   return a[i];
}
int main()
{  int k;
    node* root=NULL;
    cout<<" enter the data "<<endl;
    takeinput(&root);
    levelordertraversal(root);
    if(searchrecur(root,6)){
      cout<<endl<<" present ";
    }
    else
    {
    cout<<endl<<"not present ";
    }
    if(searchingbyloop){
      cout<<endl<<" present ";
    }
    else
    {
    cout<<endl<<"not present ";
    }
    printf("enter the value of k \n");
              scanf("%d",&k);
                printf(" %d largest Value: %d\n",k,KthLargestElement(root,k,10));
    return 0;
}
