/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(node *TreeNode) int {
    if node == nil {
		return 0
	}
	if node.Left == nil {
		return 1 + minDepth(node.Right)
	}
	if node.Right == nil {
		return 1 + minDepth(node.Left)
	}
	return 1 + int(math.Min(float64(minDepth(node.Left)), float64(minDepth(node.Right))))
}
