#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
node *buildtree(node *root)
{
    int d;
    cout << " enter the data " << endl;
    cin >> d;
    root = new node(d);
    if (d == -1)
    {
        return NULL;
    }
    cout << "enter data for inserting in left of " << d << endl;
    root->left = buildtree(root->left);
    cout << "enter data for inserting in right of " << d << endl;
    root->right = buildtree(root->right);
    return root;
}
void countleafnode(node* root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    countleafnode(root->left,count);
    if(root->right==NULL && root->left==NULL)
    {
        count++;
    }
    countleafnode(root->right,count);
}
void totalnodes(node* root,int *count)
{   
    if(root==NULL)
    {
        return;
    }
    totalnodes(root->left,count);
    *(count++);
    totalnodes(root->right,count);
}
int main()
{ 
    node *root = NULL;
    root = buildtree(root);
    int count=0;
    countleafnode(root,count);
    cout<<"the number of leaf node is "<<count;
    int tcount=0;
    totalnodes(root->right,&tcount);
    cout<<tcount;
   return 0;
}