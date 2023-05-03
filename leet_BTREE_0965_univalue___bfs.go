/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    d := [] *TreeNode {root}
    x := root.Val
    for len(d) > 0 {
        node := d[0]
        if node.Val != x {
            return false
        }
        d = d[1:]
        if node.Left != nil {
            d = append(d, node.Left)
        }
        if node.Right != nil {
            d = append(d, node.Right)
        }
    }
    return true
}
