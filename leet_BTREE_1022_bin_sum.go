/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRootToLeaf(root *TreeNode) int {

    solutions := []func(*TreeNode)int{
        // DFS,
        Simpler_DFS,
    }
    return solutions[0](root)
}

func Simpler_DFS(root * TreeNode) int {

    var Recurse func (*TreeNode, int) int
    Recurse = func (node *TreeNode, curr int) int {
        if node == nil {
            return 0
        }
        curr = (curr << 1) + node.Val
        if node.Left == nil && node.Right == nil {
            return curr
        }
        return Recurse(node.Left, curr) + Recurse(node.Right, curr)
    }
    return Recurse(root, 0)
}

func DFS(root * TreeNode) int {

    res := 0

    var Recurse func(*TreeNode, int)
    Recurse = func(node *TreeNode, curr int) {
        curr = (curr << 1) + node.Val
        if node.Left == nil && node.Right == nil {
            res += curr
        } else {
            if node.Left != nil {
                Recurse(node.Left, curr)
            }
            if node.Right != nil {
                Recurse(node.Right, curr)
            }
        }
    }

    Recurse(root, 0)
    return res
}
