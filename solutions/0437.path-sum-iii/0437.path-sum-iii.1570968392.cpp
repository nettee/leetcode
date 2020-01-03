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
    int pathSum(TreeNode* root, int sum) {
        return rootPathSum(root, sum)
            + nonRootPathSum(root, sum);
    }
    
    int rootPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        int target = sum - root->val;
        return (target == 0 ? 1 : 0) 
            + rootPathSum(root->left, target)
            + rootPathSum(root->right, target);
    }
    
    int nonRootPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        return pathSum(root->left, sum)
            + pathSum(root->right, sum);
    }
};
