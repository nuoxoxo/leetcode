/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
    Q := []*TreeNode{ root }
    S := map[int]bool{}
    for len(Q) > 0 {
        node := Q[0]
        Q = Q[1:]
        n := node.Val
        S[n] = true
        if node.Left != nil {
            Q = append(Q, node.Left)
        }
        if node.Right != nil {
            Q = append(Q, node.Right)
        }
    }
    arr := []int{}
    for key, _ := range S {
        arr = append(arr, key)
    }
    if len(arr) < 2 {
        return -1
    }
    sort.Ints(arr)
    return arr[1]
}
