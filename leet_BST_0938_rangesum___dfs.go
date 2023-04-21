func rangeSumBST(node *TreeNode, lo int, hi int) int {
	if node == nil {
		return 0
	}
	val := node.Val
	if val < lo {
		return rangeSumBST(node.Right, lo, hi)
	}
	if val > hi {
		return rangeSumBST(node.Left, lo, hi)
	}
	return val + rangeSumBST(node.Right, lo, hi) + rangeSumBST(node.Left, lo, hi)
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
