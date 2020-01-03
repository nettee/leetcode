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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* lastNode = nullptr;
        TreeNode* headNode = nullptr;
        traverse(root, lastNode, headNode);
        return headNode;
    }
    
    void traverse(TreeNode* root, TreeNode*& lastNode, TreeNode*& headNode) {
        if (root == nullptr) {
            return;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        traverse(left, lastNode, headNode);
        if (lastNode == nullptr) {
            headNode = root;
        } else {
            lastNode->right = root;
        }
        lastNode = root;
        lastNode->left = nullptr;
        lastNode->right = nullptr;
        traverse(right, lastNode, headNode);
    }
};
