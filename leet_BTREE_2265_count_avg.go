/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfSubtree(root *TreeNode) int {
    res := 0
	dq := [] * TreeNode {root}

	for len(dq) > 0 {
		ln := len(dq)

		for i := 0; i < ln; i++ {
			node := dq[0]
			dq = dq[1:]
			BFS(node, & res)

			if node.Left != nil {
				dq = append(dq, node.Left)
			}

			if node.Right != nil {
				dq = append(dq, node.Right)
			}
		}
	}

	return res
}

func BFS(node * TreeNode, res * int) {
	sum_val := 0
	sum_node := 0
	dq := [] * TreeNode {node}

	for len(dq) > 0 {
	    ln := len(dq)
		for i := 0; i < ln; i++ {
			n := dq[0]
			dq = dq[1:]
			sum_val += n.Val
			sum_node += 1
			if n.Left != nil {
				dq = append(dq, n.Left)
			}
			if n.Right != nil {
				dq = append(dq, n.Right)
			}
		}
	}

	if sum_val / sum_node == node.Val {
		*res++
	}
}

