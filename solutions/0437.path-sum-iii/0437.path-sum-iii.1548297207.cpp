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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> rc;
        int nrc = 0;
        traverse(root, sum, rc, nrc);
        return rc[sum] + nrc;
    }
    
    void traverse(TreeNode* root, int sum, unordered_map<int, int>& rcounter, int& nrcount) {
        if (root == NULL) {
            return;
        }
        rcounter[root->val]++;
        if (root->left != NULL) {
            unordered_map<int, int> rc;
            int nrc = 0;
            traverse(root->left, sum, rc, nrc);
            nrcount += nrc;
            nrcount += rc[sum];
            for (auto e : rc) {
                rcounter[e.first + root->val] += e.second;
            }
        }
        if (root->right != NULL) {
            unordered_map<int, int> rc;
            int nrc = 0;
            traverse(root->right, sum, rc, nrc);
            nrcount += nrc;
            nrcount += rc[sum];
            for (auto e : rc) {
                rcounter[e.first + root->val] += e.second;
            }
        }
    }
};
