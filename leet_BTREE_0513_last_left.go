/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) int {
    Q := []*TreeNode{ root }
    res := root.Val
    for len(Q) > 0 {
        updated := false
        temp := []*TreeNode{}
        for _, node := range Q {
            if !updated {
                res = node.Val
                updated = true
            }
            if node.Left != nil {
                temp = append(temp, node.Left)
            }
            if node.Right != nil {
                temp = append(temp, node.Right)
            }
        }
        Q = temp
    }
    return res
}
