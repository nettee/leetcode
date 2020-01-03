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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& a, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        
        int v = findMax(a, lo, hi);
        TreeNode* root = new TreeNode(a[v]);
        root->left = construct(a, lo, v-1);
        root->right = construct(a, v+1, hi);
        return root;
    }
    
    int findMax(vector<int>& a, int lo, int hi) {
        int maxi = lo;
        int maxv = a[lo];
        for (int i = lo; i <= hi; i++) {
            if (a[i] > maxv) {
                maxv = a[i];
                maxi = i;
            }            
        }
        return maxi;
    }
};
