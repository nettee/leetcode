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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> current;
        vector<vector<int>> res;
        traverse(root, current, sum, res);
        return res;
    }
    
    void traverse(TreeNode* root, vector<int>& current, int target, vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }
        
        int val = root->val;
        current.push_back(val);
        
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == target) {
                res.push_back(current);
            }
        }
        
        traverse(root->left, current, target - val, res);
        traverse(root->right, current, target - val, res);
        
        current.pop_back();
    }
};
