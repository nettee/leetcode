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
    int findTilt(TreeNode* root) {
        int tiltsum = 0;
        dfs(root, tiltsum);
        return tiltsum;
    }
    
    int dfs(TreeNode* root, int& tiltsum) {
        if (root == NULL) {
            return 0;
        }
        int lsum = dfs(root->left, tiltsum);
        int rsum = dfs(root->right, tiltsum);
        tiltsum += abs(lsum - rsum);
        return root->val + lsum + rsum;
    }
};
