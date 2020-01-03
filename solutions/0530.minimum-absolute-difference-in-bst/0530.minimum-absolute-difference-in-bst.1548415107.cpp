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
    int getMinimumDifference(TreeNode* root) {
        return get<2>(mind(root));
    }
    
    // returns (min, max, minDiff)
    tuple<int, int, int> mind(TreeNode* root) {
        if (root->left != NULL && root->right != NULL) {
            auto left = mind(root->left);
            auto right = mind(root->right);
            int leftmax = get<1>(left);
            int rightmin = get<0>(right);
            int res = min(root->val - leftmax, rightmin - root->val);
            res = min(res, get<2>(left));
            res = min(res, get<2>(right));
            return make_tuple(get<0>(left), get<1>(right), res);
        } else if (root->left != NULL) {
            auto left = mind(root->left);
            int res = root->val - get<1>(left);
            res = min(res, get<2>(left));
            return make_tuple(get<0>(left), root->val, res);
        } else if (root->right != NULL) {
            auto right = mind(root->right);
            int res = get<0>(right) - root->val;
            res = min(res, get<2>(right));
            return make_tuple(root->val, get<1>(right), res);
        } else {
            return make_tuple(root->val, root->val, (1 << 31) - 1); 
        }
    }
};
