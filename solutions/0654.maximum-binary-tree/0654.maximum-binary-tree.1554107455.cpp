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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // See https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
        deque<TreeNode*> stack;
        for (int n : nums) {
            TreeNode* node = new TreeNode(n);
            while (!stack.empty() && stack.back()->val < n) {
                node->left = stack.back();
                stack.pop_back();
            }
            if (!stack.empty()) {
                stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack.front();
    }
};
