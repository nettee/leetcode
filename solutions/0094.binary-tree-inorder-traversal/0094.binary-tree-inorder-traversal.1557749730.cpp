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
    
    void traverse(TreeNode* root, vector<int>& out) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, out);
        out.push_back(root->val);
        traverse(root->right, out);
    }
};
