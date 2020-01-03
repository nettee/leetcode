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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    
    void dfs(TreeNode* node, int& sum) {
        if (node == NULL) {
            return;
        }
        dfs(node->right, sum);
        sum += node->val;
        node->val = sum;
        dfs(node->left, sum);
    }
};
