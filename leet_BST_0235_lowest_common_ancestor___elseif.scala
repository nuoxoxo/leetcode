/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */

object Solution {
    def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode): TreeNode = {
        val         self = root.value;
        val         pv = p.value;
        val         qv = q.value;

        // dive left if greater than both p and q
        // dive right if less than both p and q

        if (self > pv && self > qv) {
            lowestCommonAncestor(root.left, p, q);
        }
        else if (self < pv && self < qv) {
            lowestCommonAncestor(root.right, p, q);
        }
        else root;
    }
}
