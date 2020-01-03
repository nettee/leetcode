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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }
        int N = inorder.size();
        return buildTree(inorder, 0, N-1, postorder, 0, N-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int lo1, int hi1, vector<int>& postorder, int lo2, int hi2) {
        if (lo1 > hi1 || lo2 > hi2) {
            return nullptr;
        }
        int rootVal = postorder[hi2];
        int k = find(inorder, lo1, hi1, rootVal);
        int leftSize = k - lo1;
        int rightSize = hi1 - k;
        int skip = lo2 + leftSize;
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(inorder, lo1, k-1, postorder, lo2, skip - 1);
        root->right = buildTree(inorder, k+1, hi1, postorder, skip, hi2 - 1);
        return root;
    }
    
    int find(vector<int>& a, int lo, int hi, int val) {
        for (int i = lo; i <= hi; i++) {
            if (a[i] == val) {
                return i;
            }
        }
        return -1;
    }
};
