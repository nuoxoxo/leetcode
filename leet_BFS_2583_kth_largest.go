/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
	D := []*TreeNode{root}
	res := []int64{}
	for len(D) > 0 {
		var level int64 = 0
		len := len(D)
		for len > 0 {
            len--
			node := D[0]
			D = D[1:]
			level += int64(node.Val)
			if node.Left != nil {
				D = append(D, node.Left)
			}
			if node.Right != nil {
				D = append(D, node.Right)
			}
		}
		res = append(res, level)
	}

	n := len(res)
	if n < k {
		return -1
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i] > res[j]
	})
	return res[k - 1]
}
