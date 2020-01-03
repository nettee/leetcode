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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        traverse(result, root, depth);
        return result;
    }
    
    void traverse(vector<vector<int>>& res, TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (res.size() <= depth) {
            vector<int> level;
            res.push_back(level);
        }
        res[depth].push_back(root->val);
        traverse(res, root->left, depth + 1);
        traverse(res, root->right, depth + 1);
    }
};
