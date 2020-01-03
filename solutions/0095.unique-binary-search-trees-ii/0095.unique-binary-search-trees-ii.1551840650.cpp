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
    vector<TreeNode*> generateTrees(int n) {
        // See #96 for DP ideas
        if (n == 0) {
            return vector<TreeNode*>();
        }
        
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        dp[0].push_back(NULL);
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= k; i++) {
                // i as root, [1..i) as left, (i..k] as right
                vector<TreeNode*> lefts = dp[i-1];
                vector<TreeNode*> rights = dp[k-i];
                for (TreeNode* l : lefts) {
                    for (TreeNode* r : rights) {
                        TreeNode* node = new TreeNode(i);
                        node->left = copyOffset(l, 0);
                        node->right = copyOffset(r, i);
                        dp[k].push_back(node);
                    }
                }
            }
        }
        return dp[n];
    }
    
    TreeNode* copyOffset(TreeNode* root, int offset) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* copy = new TreeNode(root->val + offset);
        copy->left = copyOffset(root->left, offset);
        copy->right = copyOffset(root->right, offset);
        return copy;
    }
    
};
