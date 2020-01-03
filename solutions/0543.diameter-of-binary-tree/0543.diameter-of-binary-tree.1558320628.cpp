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
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        maxDepth(root, diam);
        return diam;
    }
    
    int maxDepth(TreeNode* root, int& diam) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left, diam);
        int right = maxDepth(root->right, diam);
        diam = max(diam, left + right);
        return 1 + max(left, right);
    }
};
