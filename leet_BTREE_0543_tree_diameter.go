/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    res := 0
    dive(root, & res)
    return res
}

func dive(node *TreeNode, res *int) int {
    if node == nil {
        return 0
    }
    l := dive(node.Left, res)
    r := dive(node.Right, res)
    if *res < l + r {
        *res = l + r
    }
    curr := l
    if l < r {
        curr = r
    }
    return 1 + curr
}
