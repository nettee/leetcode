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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ls1;
        vector<int> ls2;
        leaves(root1, ls1);
        leaves(root2, ls2);
        
        if (ls1.size() != ls2.size()) {
            return false;
        }
        
        int n = ls1.size();
        for (int i = 0; i < n; i++) {
            if (ls1[i] != ls2[i]) {
                return false;
            }
        }
        return true;
    }
    
    void leaves(TreeNode* root, vector<int>& out) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            out.push_back(root->val);
        }
        
        leaves(root->left, out);
        leaves(root->right, out);
    }
};
