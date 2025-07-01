#include<iostream>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
};
class Solution {
    int height(TreeNode* root)
   {
       if(root==NULL)
       {
           return 0;
       }
       int left=height(root->left);
       int right=height(root->right);
       int ans=max(right,left)+1;
       return ans;
   }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
int op3=height(root->left)+height(root->right);
int ans=max(op3,max(op1,op2));
return ans;

    }
};