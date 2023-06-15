/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxLevelSum(root *TreeNode) int {
    if root == nil {
        return 0
    }
    D := []*TreeNode {root}
    record := math.MinInt32
    level := 0
    res := 0
    for len(D) > 0 {
        level++
        curr := 0
        size := len(D)
        i := -1
        for i < size - 1 {
            i++
            node := D[0]
            D = D[1:]
            curr += node.Val
            if node.Left != nil {
                D = append(D, node.Left)
            }
            if node.Right != nil {
                D = append(D, node.Right)
            }
        }
        if curr > record {
            res = level
        }
        record = int(math.Max(float64(curr), float64(record)))
        // record = math.Max(curr, res)
        // cannot use math.Max(curr, res) (value of type float64) as type int in assignment (solution.go)
    }
    return res
}
