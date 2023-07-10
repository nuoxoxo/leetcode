/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func minDepth(root *TreeNode) int {
    if root == nil {
		return 0
	}

	D := []*TreeNode{root}
	res := 0
	for len(D) > 0 {
		res++
		len := len(D) // level length
		for len > 0 {
			node := D[0]
			D = D[1:]
			if node.Left == nil && node.Right == nil {
				return res
			}
			if node.Left != nil {
				D = append(D, node.Left)
			}
			if node.Right != nil {
				D = append(D, node.Right)
			}
			len--
		}
	}
	return res
}

