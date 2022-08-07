class Solution {
    public TreeNode trimBST(TreeNode node, int lo, int hi)
    {
        if (node == null)
            return null;
        if (node.val < lo)
            return trimBST(node.right, lo, hi);
        if (node.val > hi)
            return trimBST(node.left, lo, hi);
        node.right = trimBST(node.right, lo, hi);
        node.left = trimBST(node.left, lo, hi);
        return node ;
    }
}


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
