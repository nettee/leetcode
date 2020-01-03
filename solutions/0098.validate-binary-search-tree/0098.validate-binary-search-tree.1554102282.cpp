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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        TreeNode* prev = nullptr;
        bool valid = true;
        traverse(root, prev, valid);
        return valid;
    }
    
    void traverse(TreeNode* root, TreeNode*& prev, bool& valid) {
        if (!valid) {
            return;
        }
        
        if (root->left != nullptr) {
            traverse(root->left, prev, valid);
        }
        if (prev != nullptr && prev->val >= root->val) {
            valid = false;
        }
        prev = root;
        if (root->right != nullptr) {
            traverse(root->right, prev, valid);
        }
    }
};
