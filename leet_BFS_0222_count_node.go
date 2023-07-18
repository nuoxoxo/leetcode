/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}

	D := []*TreeNode{ root }
	res := 0

	for len(D) > 0 {

		size := len(D)
		for i := 0; i < size; i++ {
			node := D[0]
            D = D[1:]
			if node.Left != nil {
				D = append(D, node.Left)
			}
			if node.Right != nil {
				D = append(D, node.Right)
			}
			res++
		}
	}

	return res
}
