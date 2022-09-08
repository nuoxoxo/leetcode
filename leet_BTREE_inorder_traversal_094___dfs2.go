/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorderTraversal(node *TreeNode) []int {
    E := [] int {}
    if node != nil {
        E = append(E, inorderTraversal(node.Left)...)
        E = append(E, node.Val)
        E = append(E, inorderTraversal(node.Right)...)
    }
    return E
}
