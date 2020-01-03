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
    int rob(TreeNode* root) {
        return robit(root).all;
    }

private:
    struct TravRes {
        int all;
        int withRoot;
        int withoutRoot;
        
        TravRes(int all, int withRoot, int withoutRoot) {
            this->all = all;
            this->withRoot = withRoot;
            this->withoutRoot = withoutRoot;
        }
    };
    
    TravRes robit(TreeNode* root) {
        if (root == nullptr) {
            return TravRes(0, 0, 0);
        }
        int val = root->val;
        TravRes left = robit(root->left);
        TravRes right = robit(root->right);
        int withRoot = val + left.withoutRoot + right.withoutRoot;
        int withoutRoot = left.all + right.all;
        int all = max(withRoot, withoutRoot);
        return TravRes(all, withRoot, withoutRoot);
    }
};
