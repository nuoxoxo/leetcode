/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func sumNumbers(root *TreeNode) int {
    return helper(root, 0)
}

func helper(node *TreeNode, curr int) int {
    if node == nil {
        return 0
    }
    curr = curr * 10 + node.Val
    if node.Left == nil && node.Right == nil {
        return curr
    }
    return helper(node.Left, curr) + helper(node.Right, curr)
}
