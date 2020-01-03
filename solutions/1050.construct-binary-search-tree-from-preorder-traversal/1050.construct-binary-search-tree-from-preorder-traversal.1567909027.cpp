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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int e : preorder) {
            root = insert(root, e);
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) {
            return node;
        }
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current != nullptr) {
            parent = current;
            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (val < parent->val) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        return root;
    }
};
