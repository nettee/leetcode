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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int res = 0;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* root, int& res) {
        if (root->left != NULL) {
            if (isLeaf(root->left)) {
                res += root->left->val;
            } else {
                traverse(root->left, res);
            }
        }
        if (root->right != NULL) {
            traverse(root->right, res);
        }
    }
    
    bool isLeaf(TreeNode* node) {
        return node != NULL
            && node->left == NULL
            && node->right == NULL;
    }
};
