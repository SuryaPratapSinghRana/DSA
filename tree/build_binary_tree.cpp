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
void leveloredertraversal(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL) // purana level complete traverse ho chuka h
        {
            cout << endl;
            if (!q.empty()) // queue still have some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {  cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void buildlevelorder(node* &root)
{
    queue<node*> q;
    int d;
    cout<<" enter the data for root ";
    cin>>d;
    root=new node(d);
    q.push(root);
    while(!q.empty())
    { node* temp=q.front();
      q.pop();
      cout<<" enter the left node data for "<<temp->data<<endl;
      int leftdata;
      cin>>leftdata;
      if(leftdata!=-1)
      {
        temp->left=new node(leftdata);
        q.push(temp->left);
      }
      cout<<" enter the right node data for "<<temp->data<<endl;
      int rightdata;
      cin>>rightdata;
      if(rightdata!=-1)
      {
        temp->right=new node(rightdata);
        q.push(temp->right);
      }
      

    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
   // buildlevelorder(root);
    leveloredertraversal(root);
   cout<<endl<<" inorder traversal "<<endl;
    inorder(root);
   cout<<endl<<" preorder traversal "<<endl;
    preorder(root);
   cout<<endl<<" postorder traversal "<<endl;
    postorder(root);
   // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   return 0;
}