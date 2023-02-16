/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    arr := [] *TreeNode {root}
    res := 0
    for len(arr) != 0 {
        size := len(arr)
        for i := 0; i < size; i++ {
            node := arr[0]
            arr = arr[1:]
            if node.Left != nil {
                arr = append(arr, node.Left)
            }
            if node.Right != nil {
                arr = append(arr, node.Right)
            }
        }
        res++
    }
    return res
}
