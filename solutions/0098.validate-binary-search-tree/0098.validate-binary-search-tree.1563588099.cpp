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
        bool valid = true;
        TreeNode* lastNode = nullptr;
        traverse(root, lastNode, valid);
        return valid;
    }
    
    void traverse(TreeNode* root, TreeNode*& lastNode, bool& valid) {
        if (root == nullptr) {
            return;
        }
        if (!valid) {
            return;
        }
        traverse(root->left, lastNode, valid);
        if (lastNode != nullptr) {
            if (lastNode->val >= root->val) {
                valid = false;
            }
        }
        lastNode = root;
        traverse(root->right, lastNode, valid);
    }
};
