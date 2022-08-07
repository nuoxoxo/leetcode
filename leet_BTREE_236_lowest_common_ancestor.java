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
    public TreeNode lowestCommonAncestor(TreeNode node, TreeNode p, TreeNode q) {
        TreeNode    L = new TreeNode();
        TreeNode    R = new TreeNode();

        if (node == null || node == p || node == q)
            return node;
        L = lowestCommonAncestor(node.left, p, q);
        R = lowestCommonAncestor(node.right, p, q);
        if (L == null)
            return R;
        if (R == null)
            return L;
        return node;
    }
}
