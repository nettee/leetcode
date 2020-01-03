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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int res;
        bool found = false;
        traverse(root, k, count, res, found);
        return res;
    }
    
    void traverse(TreeNode* root, int k, int& count, int& res, bool found) {
        if (root == nullptr) {
            return;
        }
        if (found) {
            return;
        }
        traverse(root->left, k, count, res, found);
        count++;
        if (count == k) {
            res = root->val;
            found = true;
        }
        traverse(root->right, k, count, res, found);
    }
};
