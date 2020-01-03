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
    public int diameterOfBinaryTree(TreeNode root) {
        int[] maxd = new int[1];
        maxd[0] = 0;
        traverse(root, maxd);
        return maxd[0];
    }
    
    // return max depth
    int traverse(TreeNode root, int[] maxd) {
        if (root == null) {
            return 0;
        }
        int left = traverse(root.left, maxd);
        int right = traverse(root.right, maxd);
        maxd[0] = Math.max(maxd[0], left + right);
        return 1 + Math.max(left, right);
    }
}
