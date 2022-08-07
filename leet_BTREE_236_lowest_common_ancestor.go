/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func lowestCommonAncestor(node, p, q *TreeNode) *TreeNode {
     if node == nil || node == p || node == q {
         return node
     }
     L := lowestCommonAncestor(node.Left, p, q)
     R := lowestCommonAncestor(node.Right, p, q)
     if (L == nil) {
         return R
     }
     if (R == nil) {
         return L
     }
     return node
}
