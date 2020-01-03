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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool> code; // true for left, false for right
        vector<bool> cp;
        vector<bool> cq;
        traverse(root, p, q, code, cp, cq);
        int i = 0;
        TreeNode* t = root;
        while (i < cp.size() && i < cq.size() && cp[i] == cq[i]) {
            if (cp[i]) {
                t = t->left;
            } else {
                t = t->right;
            }
            i++;
        }
        return t;
    }
    
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q, vector<bool>& code, vector<bool>& cp, vector<bool>& cq) {
        if (root == NULL) {
            return;
        }
        if (root == p) {
            cp = code;
        }
        if (root == q) {
            cq = code;
        }
        code.push_back(true);
        traverse(root->left, p, q, code, cp, cq);
        code.pop_back();
        code.push_back(false);
        traverse(root->right, p, q, code, cp, cq);
        code.pop_back();
    }
};
