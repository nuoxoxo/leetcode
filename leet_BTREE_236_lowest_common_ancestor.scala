/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */

object Solution {
    def lowestCommonAncestor(node: TreeNode, p: TreeNode, q: TreeNode): TreeNode = 
    {
        if (node == null || node == p || node == q) node
        else
        {
            val left = lowestCommonAncestor(node.left, p, q)
            val right = lowestCommonAncestor(node.right, p, q)
            if (left != null && right != null) node
            else if (left != null) left
            else right
        }
    }
}
