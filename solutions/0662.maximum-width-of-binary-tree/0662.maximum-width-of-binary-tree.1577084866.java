/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        left = new HashMap<>();
        maxWidth = 0;
        traverse(root, 0, 0);
        return maxWidth;
    }
    
    Map<Integer, Integer> left;
    int maxWidth;
    
    void traverse(TreeNode root, int depth, int col) {
        if (root == null) {
            return;
        }
        if (!left.containsKey(depth)) {
            left.put(depth, col);
        }
        int width = col - left.get(depth) + 1;
        maxWidth = Math.max(maxWidth, width);
        traverse(root.left, depth+1, col*2);
        traverse(root.right, depth+1, col*2+1);
    }
}
