/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root,vector<TreeNode*>&ans,int p)
    {
        if(root==NULL)
          return 0;
        ans.push_back(root);
        if(root->val==p)
        {
            return 1;
        }
    
        if(dfs(root->left,ans,p))
        {
            return 1;
        }
        if(dfs(root->right,ans,p))
            return 1;
        ans.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*>forp,forq;
        dfs(root,forp,p->val);
        dfs(root,forq,q->val);
        
         TreeNode* ans;
        for(auto it:forp)
        {
            for(auto jt:forq)
            {
                if(jt->val==it->val)
                {
                    ans=it;
                } 
            }
        }


        return ans;


    }
};