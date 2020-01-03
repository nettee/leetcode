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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            return trimBST(root->left, L, R);
        } else {
            TreeNode* node = new TreeNode(root->val);
            node->left = trimBST(root->left, L, R);
            node->right = trimBST(root->right, L, R);
            return node;
        }
    }
};
