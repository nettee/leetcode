/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        traverse(res, root, 0);
        return res;
    }
    
    void traverse(vector<vector<int>>& res, Node* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (res.size() <= depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        for (Node* child : root->children) {
            traverse(res, child, depth+1);
        }
    }
};
