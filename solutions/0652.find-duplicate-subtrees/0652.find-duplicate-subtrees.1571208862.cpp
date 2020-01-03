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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // decode every subtrees
        // decode(tree) = "val (left) (right)"
        
        unordered_map<TreeNode*, string> m;
        traverse(root, m);
        
        vector<TreeNode*> res;
        unordered_map<string, int> counter;
        for (auto& e : m) {
            if (counter[e.second] == 1) {
                res.push_back(e.first);
            }
            counter[e.second]++;
        }
        
        return res;
    }
    
    string traverse(TreeNode* root, unordered_map<TreeNode*, string>& m) {
        if (root == nullptr) {
            return "";
        }
        
        string left = traverse(root->left, m);
        string right = traverse(root->right, m);
        string code = to_string(root->val) 
                + '(' + left + ')'
                + '(' + right + ')';
        m[root] = code;
        return code;
    }
    
};
