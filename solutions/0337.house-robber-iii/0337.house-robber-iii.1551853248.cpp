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
    int rob(TreeNode* root) {
        return max(robWithRoot(root), robWithoutRoot(root));
    }
    
    int robWithRoot(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return root->val + robWithoutRoot(root->left) + robWithoutRoot(root->right);
    }
    
    int robWithoutRoot(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return rob(root->left) + rob(root->right);
    }
};
