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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
};
