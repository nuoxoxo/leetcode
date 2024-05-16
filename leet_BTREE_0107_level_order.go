/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {

    // BFS

    res := [][]int{}
    if root == nil {
        return res
    }
    deque := []*TreeNode{root}
    for len(deque) > 0 {
        N := len(deque)
        todo := []int{}
        i := 0
        for i < N {
            node := deque[0]
            deque = deque[1:]
            todo = append(todo, node.Val)
            if node.Left != nil {
                deque = append(deque, node.Left)
            }
            if node.Right != nil {
                deque = append(deque, node.Right)
            }
            i++
        }
        res = append(res, todo)
    }
    slices.Reverse(res)
    return res
}
