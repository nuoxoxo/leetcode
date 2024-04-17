/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func smallestFromLeaf(root *TreeNode) string {
    Solutions := []func(* TreeNode) string {
        DFS,
    }
    return Solutions[ 0 ]( root )
}

func DFS(root * TreeNode) string {
    res := ""
    curr := ""
    var recurse func(*TreeNode, string, *string)
    recurse = func(node *TreeNode, curr string, res *string) {
        if node == nil {
            return
        }
        curr = string(node.Val + 'a') + curr
        if node.Left == nil && node.Right == nil {
            if *res == "" || *res > curr {
                *res = curr
            }
            return
        }
        recurse (node.Left, curr, res)
        recurse (node.Right, curr, res)
    }
    recurse(root, curr, & res)
    return res
}

