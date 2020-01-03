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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> ns;
        dfs(root, 0, sums, ns);
        for (int i = 0; i < sums.size(); i++) {
            sums[i] /= ns[i];
        }
        return sums;
    }
    
    void dfs(TreeNode* root, int depth, vector<double>& sums, vector<int>& ns) {
        if (root == NULL) {
            return;
        }
        if (sums.size() == depth) {
            sums.push_back(0.0);
            ns.push_back(0);
        }
        sums[depth] += (double) root->val;
        ns[depth]++;
        dfs(root->left, depth+1, sums, ns);
        dfs(root->right, depth+1, sums, ns);
    }
};
