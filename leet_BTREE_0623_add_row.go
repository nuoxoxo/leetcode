/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/// newNode := &TreeNode{Val: 5, Left: nil, Right: nil}

func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
    Solutions := []func (*TreeNode, int, int) *TreeNode {
        // DFS,
        BFS,
    }
    return Solutions[0](root, val, depth)
}

func BFS(root *TreeNode, val int, depth int) *TreeNode {

    // assert root != nil
    if depth == 1 {
        return & TreeNode {Val: val, Left: root, Right: nil}
    }
    Q := []*TreeNode{ root }
    for len(Q) != 0 {
        depth--
        if depth == 0 {
            return root
        }
        var L, R *TreeNode
        N := len(Q)
        for N > 0 {
            node := Q[0]
            Q = Q[1:]
            N--
            if (depth == 1) {
                L = & TreeNode {Val: val, Left:node.Left,   Right:nil}
                R = & TreeNode {Val: val, Left:nil,         Right:node.Right}
                node.Left, node.Right = L, R
            } else {
                if node.Left != nil {
                    Q = append(Q, node.Left)
                }
                if node.Right != nil {
                    Q = append(Q, node.Right)
                }
            }
        }
    }
    return root
}

func DFS(root *TreeNode, val int, depth int) *TreeNode {

    if root == nil {

        return root
    }

    if depth == 1 {

        return & TreeNode {Val: val, Left: root, Right: nil}
    }

    if depth == 2 {
        L := & TreeNode {Val: val, Left:nil, Right:nil}
        R := & TreeNode {Val: val, Left:nil, Right:nil}
        L.Left, R.Right = root.Left, root.Right
        root.Left = L
        root.Right = R
        return root
    }

    root.Left = DFS(root.Left, val, depth - 1)
    root.Right = DFS(root.Right, val, depth - 1)
    return root
}
