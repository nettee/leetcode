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
        string pcode = encode(root, p->val);
        string qcode = encode(root, q->val);
        int i = 0;
        while (i < pcode.length() && i < qcode.length() && pcode[i] == qcode[i]) {
            i++;
        }
        string compre(pcode, 0, i);
        return locate(root, compre);
    }
    
    string encode(TreeNode* root, int val) {
        string res;
        bool found = false;
        encode(root, val, "", found, res);
        return res;
    }
    
    void encode(TreeNode* root, int val, string s, bool& found, string& res) {
        if (found) {
            return;
        }
        if (root == NULL) {
            return;
        }
        if (root->val == val) {
            found = true;
            res = s;
            return;
        }
        encode(root->left, val, s + '0', found, res);
        encode(root->right, val, s + '1', found, res);
    }
    
    TreeNode* locate(TreeNode* root, const string& compre) {
        return locate(root, compre, 0);
    }
    
    TreeNode* locate(TreeNode* root, const string& compre, int i) {
        if (i >= compre.length()) {
            return root;
        }
        if (compre[i] == '0') {
            return locate(root->left, compre, i+1);
        } else {
            return locate(root->right, compre, i+1);
        }
    }
};
