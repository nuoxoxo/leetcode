/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func averageOfLevels(root *TreeNode) []float64 {
    res := [] float64 {}
    dq := [] *TreeNode { root } // deque is slice in go 
    for len(dq) > 0 {
        var tmp int64 = 0
        size := len(dq)
        for _, node := range dq {
            tmp += int64(node.Val)
            dq = dq[1:]
            if node.Left != nil {
                dq = append(dq, node.Left)
            }
            if node.Right != nil {
                dq = append(dq, node.Right)
            }
        }
        res = append(res, float64(tmp) / float64(size))
    }
    return res
}
