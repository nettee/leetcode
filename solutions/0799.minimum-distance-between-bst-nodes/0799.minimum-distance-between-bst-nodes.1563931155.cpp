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
    int minDiffInBST(TreeNode* root) {
        int mind = -1;
        TreeNode* lastNode = nullptr;
        traverse(root, lastNode, mind);
        return mind;
    }
    
    void traverse(TreeNode* root, TreeNode*& lastNode, int& mind) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, lastNode, mind);
        if (lastNode != nullptr) {
            int diff = root->val - lastNode->val;
            if (mind == -1 || diff < mind) {
                mind = diff;
            }
        }
        lastNode = root;
        traverse(root->right, lastNode, mind);
    }
};
