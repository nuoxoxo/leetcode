/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func pruneTree(node *TreeNode) *TreeNode {
    if node == nil {return node}
    node.Left = pruneTree(node.Left)
    node.Right = pruneTree(node.Right)
    if node.Left == nil && node.Right == nil && node.Val == 0 {
        return nil
    }
    return node
}
