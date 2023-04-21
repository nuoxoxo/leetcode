/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    dq := [] *TreeNode { root }
    a := [] int {}
    for len(dq) != 0 {
        temp := dq[0]
        dq = dq[1:]
        n := temp.Val
        if n <= high && n >= low {
            a = append(a, n)
        }
        if temp.Left != nil {
            dq = append(dq, temp.Left)
        }
        if temp.Right != nil {
            dq = append(dq, temp.Right)
        }
    }
    res := 0
    for _, n := range a {
        res += n
    }
    return res
}
