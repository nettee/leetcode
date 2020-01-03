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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xParent = nullptr;
        int xDepth = -1;
        TreeNode* yParent = nullptr;
        int yDepth = -1;
        traverse(root, nullptr, 0, x, y, xParent, xDepth, yParent, yDepth);
        return xDepth != -1 && yDepth != -1 && xDepth == yDepth
            && xParent != nullptr && yParent != nullptr && xParent != yParent;
    }
    
    void traverse(TreeNode* root, TreeNode* parent, int depth, int x, int y, 
                  TreeNode*& xParent, int& xDepth, TreeNode*& yParent, int& yDepth) {
        if (root == nullptr) {
            return;
        }
        if (root->val == x) {
            xParent = parent;
            xDepth = depth;
        }
        if (root->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        traverse(root->left, root, depth+1, x, y, xParent, xDepth, yParent, yDepth);
        traverse(root->right, root, depth+1, x, y, xParent, xDepth, yParent, yDepth);
    }
};
