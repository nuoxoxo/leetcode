/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorderTraversal(root *TreeNode) []int {
    E := [] int {}
    inorder(root, E)
    return E
}

func inorder(node *TreeNode, E [] int) {
    if node == nil { return }
    inorder(node.Left, E)
    E = append(E, node.Val)
    inorder(node.Right, E)
}
