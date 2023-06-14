/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDiffInBST(root *TreeNode) int {
	dq := []*TreeNode {root}
	var n []int

	for len(dq) > 0 {
		node := dq[0]
		dq = dq[1:]
		n = append(n, node.Val)
		if node.Left != nil {
			dq = append(dq, node.Left)
		}
		if node.Right != nil {
			dq = append(dq, node.Right)
		}
	}

    sort.Ints(n)
	len := len(n)
	res := math.MaxInt32
	for i := 0; i < len - 1; i++ {
		tmp := n[i + 1] - n[i]
		if res > tmp {
			res = tmp
		}
	}

	return res
}
