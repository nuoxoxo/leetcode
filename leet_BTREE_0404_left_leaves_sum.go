/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
    Solutions := []func( *TreeNode ) int {
        // DFS_alt,
        // DFS,
        BFS,
    }
    return Solutions[0](root)
}

func BFS(node *TreeNode) int {
    type _Node struct {
        _node *TreeNode
        _isLeft bool
    }
    res := 0
    Q := [] _Node {{_node: node, _isLeft: false}}
    for len(Q) != 0 {
        curr := Q[len(Q) - 1]
        Q = Q[:len(Q) - 1]
        if curr._isLeft && curr._node.Left == nil && curr._node.Right == nil {
            res += curr._node.Val
        }
        if curr._node.Left != nil {
            Q = append(Q, _Node {_node: curr._node.Left, _isLeft: true})
        }
        if curr._node.Right != nil {
            Q = append(Q, _Node {_node: curr._node.Right, _isLeft: false})
        }
    }
    return res
}

func DFS(node * TreeNode) int {
    var dfs func (*TreeNode, bool) int
    dfs = func(node * TreeNode, LEFT bool) int {
        if node == nil {
            return 0
        }
        if node.Left == nil && node.Right == nil {
            if !LEFT {
                return 0
            }
            return node.Val
        }
        return dfs(node.Left, true) + dfs(node.Right, false)
    }
    return dfs(node, false)
}

func DFS_alt(node *TreeNode) int {
    if node == nil {
        return 0
    }
    if node.Left != nil && node.Left.Left == nil && node.Left.Right == nil {
        return node.Left.Val + DFS_alt (node.Right)
    }
    return DFS_alt (node.Left) + DFS_alt (node.Right)
}

