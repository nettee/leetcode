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
        dfs(root, maxd);
        return maxd;
    }
    
    // return depth
    int dfs(TreeNode* root, int& maxd) {
        if (root == NULL) {
            return 0;
        }
        int ldepth = dfs(root->left, maxd);
        int rdepth = dfs(root->right, maxd);
        maxd = max(maxd, ldepth + rdepth);
        return 1 + max(ldepth, rdepth);
    }
};
