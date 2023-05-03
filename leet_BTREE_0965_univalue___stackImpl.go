/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isUnivalTree(root *TreeNode) bool {
    d := make(Stack, 0)
    d.Push(root)
    x := root.Val
    for !d.Empty() {
        node := d.Pop()
        if node.Val != x {
            return false
        }
        if node.Left != nil {
            d.Push(node.Left)
        }
        if node.Right != nil {
            d.Push(node.Right)
        }
    }
    return true
}

type Stack [] *TreeNode

func (d *Stack) Empty() bool {
    return len(*d) == 0
}

func (d *Stack) Push(node *TreeNode) {
    *d = append(*d, node)
}

func (d *Stack) Pop() *TreeNode {
    node := (*d)[len(*d) - 1]
    *d = (*d)[:len(*d) - 1]
    return node
}


