/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) int {
    Solutions := []func(*TreeNode)int{
        BFS, // liked
        DFS, // 🤔
    }
    return Solutions[1/*0*/](root)
}

func BFS (root *TreeNode) int {
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

func DFS (root *TreeNode) int {
    res := root.Val
    maxlevel := -1
    var Solver func( * TreeNode, int )
    Solver = func( node * TreeNode, level int ) {
        if node == nil {
            return
        }
        if node.Left == nil && maxlevel < level {
            res, maxlevel = node.Val, level
        }
        Solver(node.Left, level + 1)
        Solver(node.Right, level + 1)
    }
    Solver( root, 1 )
    return res

}

