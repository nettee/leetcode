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
        return pathSumWithRoot(root, sum) + pathSumWithoutRoot(root, sum);
    }
    
    int pathSumWithRoot(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return (root->val == sum ? 1 : 0)
            + pathSumWithRoot(root->left, sum - root->val)
            + pathSumWithRoot(root->right, sum - root->val);
    }
    
    int pathSumWithoutRoot(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
