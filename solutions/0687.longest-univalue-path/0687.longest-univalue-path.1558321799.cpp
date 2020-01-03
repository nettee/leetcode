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
    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;
        maxPathDepth(root, longest);
        return longest;
    }
    
    int maxPathDepth(TreeNode* root, int& longest) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = maxPathDepth(root->left, longest);
        if (root->left == nullptr || root->left->val != root->val) {
            left = 0;
        }
        int right = maxPathDepth(root->right, longest);
        if (root->right == nullptr || root->right->val != root->val) {
            right = 0;
        }
        
        longest = max(longest, left + right);
        return 1 + max(left, right);
    }
};
