/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    Solutions := []func(* TreeNode, int, int) int {
        inorder,
        // BFS,
        // DFS,
    }
    return Solutions[ 0 ]( root, low, high )
}

func inorder(root *TreeNode, low int, high int) int {

    res := 0
    var traverse func( * TreeNode )
    traverse = func(node * TreeNode) {
        if node == nil {
            return
        }
        traverse(node.Left)
        n := node.Val
        if low <= n && n <= high {
            res += n
        }
        traverse(node.Right)
    }
    traverse(root)
    return res
}

func BFS(root *TreeNode, low int, high int) int {
    Q := [] *TreeNode { root }
    arr := []int{}
    for len(Q) > 0 {
        node := Q[0]
        Q = Q[1:]
        n := node.Val
        if low <= n && n <= high {
            arr = append(arr, n)
        }
        if node.Left != nil {
            Q = append(Q, node.Left)
        }
        if node.Right != nil {
            Q = append(Q, node.Right)
        }
    }
    res := 0
    for _, n := range arr {
        res += n
    }
    return res
}

func DFS (root * TreeNode, low int, high int) int {
    res := 0
    var recurse func( * TreeNode )
    recurse = func(node * TreeNode) {
        if node == nil {
            return
        }
        n := node.Val
        if low <= n && n <= high {
            res += n
        }
        if low < n {
            recurse(node.Left)
        }
        if n < high {
            recurse(node.Right)
        }
    }
    recurse(root)
    return res
}

