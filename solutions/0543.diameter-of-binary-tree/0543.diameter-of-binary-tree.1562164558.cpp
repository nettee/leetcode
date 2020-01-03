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
        int maxd = 0;
        traverse(root, maxd);
        return maxd;
    }
    
    // return: tree max depth
    int traverse(TreeNode* root, int& maxd) {
        if (root == nullptr) {
            return 0;
        }
        int left = traverse(root->left, maxd);
        int right = traverse(root->right, maxd);
        maxd = max(maxd, left + right);
        return 1 + max(left, right);
    }
};
