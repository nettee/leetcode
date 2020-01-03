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
        bool balanced = true;
        traverse(root, balanced);
        return balanced;
    }
    
    // return depth
    int traverse(TreeNode* root, bool& balanced) {
        if (root == nullptr) {
            return 0;
        }
        int left = traverse(root->left, balanced);
        int right = traverse(root->right, balanced);
        if (abs(left - right) > 1) {
            balanced = false;
        }
        return 1 + max(left, right);
    }
};
