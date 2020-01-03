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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& pre, int b0, int e0, vector<int>& in, int b1, int e1) {
        if (b0 >= e0 || b1 >= e1) {
            return nullptr;
        }
        int rootVal = pre[b0];
        int offset = findOffset(in, b1, e1, rootVal);
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pre, b0 + 1, b0 + 1 + offset, in, b1, b1 + offset);
        root->right = build(pre, b0 + 1 + offset, e0, in, b1 + offset + 1, e1);
        return root;
    }
    
    int findOffset(vector<int>& in, int b1, int e1, int target) {
        for (int i = b1; i < e1; i++) {
            if (in[i] == target) {
                return i - b1;
            }
        }
        return 0;
    }
};
