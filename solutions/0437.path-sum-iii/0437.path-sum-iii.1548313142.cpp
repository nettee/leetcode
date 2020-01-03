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
        if (root == NULL) {
            return 0;
        }
        return rootSum(root, sum)
            + pathSum(root->left, sum)
            + pathSum(root->right, sum);
    }
    
    int rootSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;    
        }
        return (root->val == sum ? 1 : 0)
            + rootSum(root->left, sum - root->val)
            + rootSum(root->right, sum - root->val);
    }
};
