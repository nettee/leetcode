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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        
        int val = root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return val == sum;
        } else if (root->left == nullptr) {
            return hasPathSum(root->right, sum - val);
        } else if (root->right == nullptr) {
            return hasPathSum(root->left, sum - val);
        } else {
            return hasPathSum(root->left, sum - val)
                || hasPathSum(root->right, sum - val);
        }
    }
};
