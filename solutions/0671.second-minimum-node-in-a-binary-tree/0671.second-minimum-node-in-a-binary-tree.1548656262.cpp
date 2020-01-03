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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        if (root->left == NULL && root->right == NULL) {
            return -1;
        }
        int minimum = root->val;
        int res = -1;
        dfs(root, minimum, res);
        return res;
    }
    
    void dfs(TreeNode* root, int minimum, int& res) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL) {
            return;
        }
        if (root->left->val == minimum && root->right->val == minimum) {
            dfs(root->left, minimum, res);
            dfs(root->right, minimum, res);
        } else if (root->left->val == minimum) {
            if (res == -1) {
                res = root->right->val;
            } else if (res != -1 && root->right->val < res) {
                res = root->right->val;
            }
            dfs(root->left, minimum, res);
        } else {
            if (res == -1) {
                res = root->left->val;
            } else if (res != -1 && root->left->val < res) {
                res = root->left->val;
            }
            dfs(root->right, minimum, res);
        }
    }
};
