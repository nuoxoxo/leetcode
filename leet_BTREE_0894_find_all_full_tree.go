/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func allPossibleFBT(n int) []*TreeNode {
	if n == 1 {
		return []*TreeNode{ &TreeNode {}}
	}
	if n%2 == 0 {
		return []*TreeNode {}
	}

	var res []*TreeNode
	i := 1
	for i < n - 1 {
		L := allPossibleFBT(i)
		R := allPossibleFBT(n - i - 1)
		for _, l := range L {
			for _, r := range R {
				node := & TreeNode{}
				node.Left = l
				node.Right = r
				res = append(res, node)
			}
		}
		i += 2
	}
	return res
}

