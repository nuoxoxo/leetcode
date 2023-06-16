/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
    dq := []*TreeNode {root}
    var node * TreeNode
    var level int
    res := 0
    for len(dq) > 0 {
        res = 0
        level = len(dq)
        for level > 0 {
            level--
            node = dq[0]
            dq = dq[1:]
            res += node.Val
            if node.Left != nil {
                dq = append(dq, node.Left)
            }
            if node.Right != nil {
                dq = append(dq, node.Right)
            }
        }
    }
    return res
}
