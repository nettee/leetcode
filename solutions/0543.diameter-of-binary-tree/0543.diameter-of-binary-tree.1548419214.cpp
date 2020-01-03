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
        if (root == NULL) {
            return 0;
        }
        return dfs(root).first;
    }
    
    // (maxd, depth)
    pair<int, int> dfs(TreeNode* root) {
        if (root->left != NULL && root->right != NULL) {
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            int maxd = max(max(left.first, right.first),
                          2 + left.second + right.second);
            int depth = 1 + max(left.second, right.second);
            return make_pair(maxd, depth);
        } else if (root->left != NULL) {
            auto left = dfs(root->left);
            int maxd = max(left.first, 1 + left.second);
            int depth = 1 + left.second;
            return make_pair(maxd, depth);
        } else if (root->right != NULL) {
            auto right = dfs(root->right);            
            int maxd = max(right.first, 1 + right.second);
            int depth = 1 + right.second;
            return make_pair(maxd, depth);
        } else {
            return make_pair(0, 0);
        }
    }
};
