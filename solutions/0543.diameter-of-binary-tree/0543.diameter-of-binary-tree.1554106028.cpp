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
        int maxDiam = 0;
        maxHeight(root, maxDiam);
        return maxDiam;
    }
    
    int maxHeight(TreeNode* root, int& maxDiam) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxHeight(root->left, maxDiam);
        int right = maxHeight(root->right, maxDiam);
        maxDiam = max(maxDiam, left + right);
        return 1 + max(left, right);
    }
};
