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
    int rob(TreeNode* root) {
        auto res = rob0(root);
        return max(res.first, res.second);
    }
    
    // returns (withRoot, withoutRoot)
    pair<int, int> rob0(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        auto left = rob0(root->left);
        auto right = rob0(root->right);
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(withRoot, withoutRoot);
    }
};
