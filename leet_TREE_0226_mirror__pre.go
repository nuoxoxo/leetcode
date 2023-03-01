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
    node.Left, node.Right = node.Right, node.Left
    invertTree(node.Left)
    invertTree(node.Right)
    return node
}
