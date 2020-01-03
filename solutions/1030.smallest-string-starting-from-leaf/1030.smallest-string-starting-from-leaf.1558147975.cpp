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
    string smallestFromLeaf(TreeNode* root) {
        string current;
        string smallest;
        traverse(root, current, smallest);
        return smallest;
    }
    
    void traverse(TreeNode* root, string& current, string& smallest) {
        if (root == nullptr) {
            return;
        }
        
        char c = 'a' + root->val;
        current += c;
        
        if (root->left == nullptr && root->right == nullptr) {
            string t = current;
            reverse(t.begin(), t.end());
            if (smallest.empty() || t < smallest) {
                smallest = t;
            }
        }
        
        traverse(root->left, current, smallest);
        traverse(root->right, current, smallest);
        
        current.pop_back();
    }
};
