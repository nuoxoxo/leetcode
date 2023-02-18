/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(node *TreeNode) *TreeNode {
    if node == nil {
        return node
    }
    invertTree(node.Left)
    invertTree(node.Right)
    node.Left, node.Right = node.Right, node.Left
    return node
}
