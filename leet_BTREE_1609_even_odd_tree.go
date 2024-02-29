/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isEvenOddTree(root *TreeNode) bool {
    Solutions := []func( * TreeNode) bool {
        Solution_BFS,
    }
    return Solutions[ 0 ]( root )
}

func Solution_BFS (root * TreeNode) bool {
    if root == nil {
        return true
    }
    Q := []*TreeNode{root}
    level := 0
    for len(Q) > 0 {
        level++
        temp := []*TreeNode{}
        prev := 0
        for _, node := range Q {
            val := node.Val
            isEven := (level % 2 == 0)
            if (val % 2 == 0) == isEven  {
                return false
            }
            if isEven && prev > 0 && prev <= val {
                return false
            }
            if ! isEven && prev >= val {
                return false
            }
            if node.Left != nil {
                temp = append( temp, node.Left )
            }
            if node.Right != nil {
                temp = append( temp, node.Right )
            }
            prev = val
        }
        Q = temp
    }
    return true
}
