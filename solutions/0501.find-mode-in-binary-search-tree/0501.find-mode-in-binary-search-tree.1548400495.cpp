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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        traverse(root, counter);
        int mc = 0;
        for (auto e : counter) {
            mc = max(mc, e.second);
        }
        vector<int> res;
        for (auto e : counter) {
            if (e.second == mc) {
                res.push_back(e.first);
            }
        }
        return res;
    }
    
    void traverse(TreeNode* root, unordered_map<int, int>& counter) {
        if (root == NULL) {
            return;
        }
        counter[root->val]++;
        traverse(root->left, counter);
        traverse(root->right, counter);
    }
};
