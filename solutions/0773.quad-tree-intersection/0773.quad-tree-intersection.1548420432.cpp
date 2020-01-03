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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return interleaf(quadTree1, quadTree2);
        } else if (quadTree2->isLeaf) {
            return interleaf(quadTree2, quadTree1);
        } else {
            Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf
                && tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
                return new Node(tl->val, true, NULL, NULL, NULL, NULL);
            } else {
                return new Node(false, false, tl, tr, bl, br);
            }
        }
    }
    
    Node* interleaf(Node* leaf, Node* other) {
        if (leaf->val) {
            return leaf;
        } else {
            return other;
        }
    }
};
