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
        // BFS version
        if (root == NULL) {
            return vector<double>();
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;

        while (!q.empty()) {
            int n = q.size();
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                sum += (double) node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                q.pop();
            }
            res.push_back(sum / n);
        }
        
        return res;
    }
};
