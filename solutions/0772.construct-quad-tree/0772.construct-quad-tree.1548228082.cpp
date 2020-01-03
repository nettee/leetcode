/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        Node* root = build(grid, 0, 0, N);
        return root;
    }
    
    Node* build(vector<vector<int>>& grid, int x, int y, int n) {
        if (allSame(grid, x, y, n)) {
            // Leaf node
            bool val = grid[y][x];
            return new Node(val, true, NULL, NULL, NULL, NULL);
        } else {
            // Non-leaf node
            Node* topLeft = build(grid, x, y, n/2);
            Node* topRight = build(grid, x+n/2, y, n/2);
            Node* bottomLeft = build(grid, x, y+n/2, n/2);
            Node* bottomRight = build(grid, x+n/2, y+n/2, n/2);
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
    
    bool allSame(vector<vector<int>>& grid, int x, int y, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[y+i][x+j] != grid[y][x]) {
                    return false;
                }
            }
        }
        return true;
    }
};
