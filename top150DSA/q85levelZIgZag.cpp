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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
         vector<vector<int>>ans;
        queue<TreeNode*> q;
        q.push(root);
        int num=0;
        while (!q.empty()) {
            int size = q.size();
            vector<int>lev;
            num++;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                lev.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            if(num%2==0)
              reverse(lev.begin(),lev.end());
            ans.push_back(lev);
        }

        return ans;
    }
};