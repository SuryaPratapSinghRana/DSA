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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
          return {};
    vector<double>res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        double sum=0;
        int count=size;
        while(size--)
        {
            TreeNode* temp=q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left!=NULL)
              q.push(temp->left);
            if(temp->right!=NULL)
              q.push(temp->right);
            
        }
        double ans=(sum*1.0)/count;
        res.push_back(ans);
    }

    return res;
    }
};