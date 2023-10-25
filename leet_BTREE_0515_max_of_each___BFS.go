/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import (
    "container/list"
    "math"
)

func largestValues(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }

    D := list.New()
    D.PushBack(root)
    var res []int

    for D.Len() > 0 {
        len := D.Len()
        temp := math.MinInt32

        for i := 0; i < len; i++ {
            node := D.Remove(D.Front()).(*TreeNode)
            temp = int(math.Max(float64(temp), float64(node.Val)))

            if node.Left != nil {
                D.PushBack(node.Left)
            }
            if node.Right != nil {
                D.PushBack(node.Right)
            }
        }

        res = append(res, temp)
    }

    return res
}
