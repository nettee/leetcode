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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return vector<TreeNode*>();
        }
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int lo, int hi) {
        if (hi < lo) {
            return vector<TreeNode*>{nullptr};
        } else if (hi == lo) {
            return vector<TreeNode*>{new TreeNode(lo)};
        } else {
            vector<TreeNode*> res;
            for (int v = lo; v <= hi; v++) {
                vector<TreeNode*> lefts = generateTrees(lo, v-1);
                vector<TreeNode*> rights = generateTrees(v+1, hi);
                for (TreeNode* left : lefts) {
                    for (TreeNode* right : rights) {
                        TreeNode* root = new TreeNode(v);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
                
            }
            return res;
        }
    }
};
