/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isUnivalTree(root *TreeNode) bool {
    d := make(Queue, 0)
    d.Push(root)
    x := root.Val
    for !d.Empty() {
        node := d.Shift()
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

type Queue [] *TreeNode

func (d *Queue) Empty() bool {
    return len(*d) == 0
}

func (d *Queue) Push(node *TreeNode) {
    *d = append(*d, node)
}

func (d *Queue) Shift() *TreeNode {
    node := (*d)[0]
    *d = (*d)[1:]
    return node
}


