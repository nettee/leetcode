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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBst(nums, 0, nums.size() - 1);
    }
    
    TreeNode* toBst(vector<int>& a, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = toBst(a, lo, mid - 1);
        root->right = toBst(a, mid + 1, hi);
        return root;
    }
};
