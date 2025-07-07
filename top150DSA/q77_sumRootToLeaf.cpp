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
    int sumNumbers(TreeNode* root, int path = 0) {
        if(root == NULL) return 0;
        else if(root->left == NULL && root->right == NULL)
            return (path*10 + root->val);
        return sumNumbers(root->left, path*10 + root->val) + sumNumbers(root->right, path*10 + root->val);
    }
};