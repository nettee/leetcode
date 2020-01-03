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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return vector<string>();
        } else if (root->left == NULL && root->right == NULL) {
            return vector<string>{to_string(root->val)};
        }
        vector<string> res;
        string base = to_string(root->val);
        traverse(root, base, res);
        return res;
    }
    
    void traverse(TreeNode* root, string s, vector<string>& res) {
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s);
            return;
        }
        if (root->left != NULL) {
            traverse(root->left, s + "->" + to_string(root->left->val), res);
        }
        if (root->right != NULL) {
            traverse(root->right, s + "->" + to_string(root->right->val), res);
        }
    }
};
