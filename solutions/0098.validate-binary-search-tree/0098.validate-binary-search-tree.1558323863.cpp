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
        TreeNode* last = nullptr;
        bool valid = true;
        traverse(root, last, valid);
        return valid;
    }
    
    void traverse(TreeNode* root, TreeNode*& last, bool& valid) {
        if (root == nullptr) {
            return;
        }
        
        traverse(root->left, last, valid);
        
        if (last != nullptr && last->val >= root->val) {
            valid = false;
        }
        last = root;
        
        traverse(root->right, last, valid);
    }
};
