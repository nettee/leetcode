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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return check(root).first;
    }
    
    // return <balanced, depth>
    pair<bool, int> check(TreeNode* root) {
        if (root == NULL) {
            return make_pair(true, 0);
        }
        pair<bool, int> pl = check(root->left);
        pair<bool, int> pr = check(root->right);
        bool balanced = pl.first && pr.first && abs(pl.second - pr.second) <= 1;
        int depth = 1 + max(pl.second, pr.second);
        return make_pair(balanced, depth);
    }
};
