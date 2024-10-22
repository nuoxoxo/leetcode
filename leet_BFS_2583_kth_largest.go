/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
    solutions := []func(*TreeNode, int)int64{
        BFS,
    }
    return solutions[0]( root, k )
}

func BFS(root *TreeNode, k int) int64 {
	D := []*TreeNode{root}
	res := []int64{}
	for len(D) > 0 {
		var level int64 = 0
	    N := len(D)
		for N > 0 {
			node := D[0]
			D = D[1:]
			if node.Left != nil { D = append(D, node.Left) }
			if node.Right != nil { D = append(D, node.Right) }
            level += int64(node.Val)
            N--
		}
		res = append(res, level)
	}

	N := len(res)
	if N < k {
		return -1
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i] > res[j]
	})
	return res[k - 1]

    // sort.Ints(res) // bc. it's a int64 slice so we can't use Ints
    // return res[N - k]

}
