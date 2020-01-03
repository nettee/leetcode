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
        return hasSum(root, 0, sum);
    }
    
    bool hasSum(TreeNode* root, int sum, int expected) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val + sum == expected;
        }
        int newsum = sum + root->val;
        return hasSum(root->left, newsum, expected)
            || hasSum(root->right, newsum, expected);
    }
};
