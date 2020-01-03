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
    public int getMinimumDifference(TreeNode root) {
        lastNode = null;
        minDiff = Integer.MAX_VALUE;
        traverse(root);
        return minDiff;
    }
    
    TreeNode lastNode;
    int minDiff;
    
    void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        traverse(root.left);
        if (lastNode != null) {
            int diff = root.val - lastNode.val;
            minDiff = Math.min(minDiff, diff);
        }
        lastNode = root;
        traverse(root.right);
    }
}
