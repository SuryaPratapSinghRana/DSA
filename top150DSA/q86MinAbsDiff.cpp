/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int maxval(TreeNode* root)
   {
     if(root==NULL)
      return INT_MIN;
      return max(maxval(root->right),root->val);
   }
   int minval(TreeNode* root)
   {
     if(root==NULL)
      return INT_MAX;
      return min(minval(root->left),root->val);
   }
   void mindiff(TreeNode* root,int &mini)
   {
    if(root==NULL)
       return;
    if(root->left!=NULL)
    {
        mini=min(mini,abs(root->val-maxval(root->left)));
    }
    if(root->right!=NULL)
    {
        mini=min(mini,abs(root->val-minval(root->right)));
    }
    mindiff(root->left,mini);
    mindiff(root->right,mini);
   }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        mindiff(root,mini);
        return mini;
    }
};