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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> order1;
        vector<int> order2;
        inorder(root1, order1);
        inorder(root2, order2);
        
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < order1.size() || j < order2.size()) {
            int d;
            if (i == order1.size()) {
                d = order2[j++];
            } else if (j == order2.size()) {
                d = order1[i++];
            } else if (order1[i] < order2[j]) {
                d = order1[i++];
            } else {
                d = order2[j++];
            }
            res.push_back(d);
        }
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
