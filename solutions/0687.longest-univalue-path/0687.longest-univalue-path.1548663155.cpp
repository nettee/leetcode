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
        dfs(root, longest);
        return longest;
    }
    
    // return root-longest
    int dfs(TreeNode* root, int& longest) {
        if (root == NULL) {
            return 0;
        }
        if (root->left != NULL && root->right != NULL) {
            int left = dfs(root->left, longest);
            int right = dfs(root->right, longest);
            if (root->val == root->left->val && root->val == root->right->val) {
                longest = max(longest, 2 + left + right);
                return 1 + max(left, right);
            } else if (root->val == root->left->val) {
                longest = max(longest, 1 + left);
                return 1 + left;
            } else if (root->val == root->right->val) {
                longest = max(longest, 1 + right);
                return 1 + right;
            } else {
                return 0;
            }
        } else if (root->left != NULL) {
            int left = dfs(root->left, longest);
            if (root->val == root->left->val) {
                longest = max(longest, 1 + left);
                return 1 + left;
            } else {
                return 0;
            }
        } else if (root->right != NULL) {
            int right = dfs(root->right, longest);    
            if (root->val == root->right->val) {
                longest = max(longest, 1 + right);
                return 1 + right;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
        
    }
};
