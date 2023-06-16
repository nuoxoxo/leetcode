/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func reverseOddLevels(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }


    dq := []*TreeNode{root}
    level := 0
    var line []int

    for len(dq) > 0 {
        var kids []int
        size := len(dq)
         for size > 0 {
            size--
            node := dq[0]
            dq = dq[1:]
            if level % 2 != 0 {
                node.Val = line[size]
            }
            if node.Left != nil {
                dq = append(dq, node.Left)
                kids = append(kids, node.Left.Val)
            }
            if node.Right != nil {
                dq = append(dq, node.Right)
                kids = append(kids, node.Right.Val)
            }
        }
        level++
        line = kids
    }
    return root
}
