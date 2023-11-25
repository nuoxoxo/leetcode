/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMode(root *TreeNode) []int {
    if root == nil {
        return [] int {}
    }
    res := []int{}
    dq := [] *TreeNode { root }
    D := make(map[int]int)
    occ := 0
    for len(dq) > 0 {
        node := dq[0]
        dq = dq[1:]
        D[node.Val] += 1
        if occ < D[node.Val] {
            occ = D[node.Val]
        }
        if node.Left != nil {
            dq = append(dq, node.Left)
        }
        if node.Right != nil  {
            dq = append(dq, node.Right)
        }
    }
    for key, val := range D {
        if val == occ {
            res = append(res, key)
        }
    }
    return res
}

