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
        } 
        
        bool res = false;
        if (root->left != nullptr) {
            res = res || hasPathSum(root->left, sum - val);
        }
        if (root->right != nullptr) {
            res = res || hasPathSum(root->right, sum - val);
        }
        return res;
    }
};
