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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int prestart,int preend,unordered_map<int,int>&m
    )
    {     if(instart>inend || prestart>preend) return NULL;
          TreeNode* root= new TreeNode(preorder[prestart]);
          int inroot=m[root->val];
          int numleft=inroot-instart;
          root->left=build(preorder,inorder,instart,inroot-1,prestart+1,prestart+numleft,m);
          root->right=build(preorder,inorder,inroot+1,inend,prestart+numleft+1,preend,m);
          return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
           m[inorder[i]]=i;
        }
       return build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,m);

    }
};