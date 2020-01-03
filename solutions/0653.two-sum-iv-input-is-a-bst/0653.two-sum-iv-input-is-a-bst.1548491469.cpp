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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        tolist(root, nums);
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n == k - n) {
                if (i < nums.size() - 1 && n == nums[i+1]) {
                    return true;
                }
            } else {
                if (contains(root, k - n)) {
                    return true;
                }
            }
        } 
        return false;
    }
    
    void tolist(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        tolist(root->left, res);
        res.push_back(root->val);
        tolist(root->right, res);
    }
    
    bool contains(TreeNode* root, int val) {
        if (root == NULL) {
            return false;
        }
        if (root->val > val) {
            return contains(root->left, val);
        } else if (root->val < val) {
            return contains(root->right, val);
        } else {
            return true;
        }
    }
};
