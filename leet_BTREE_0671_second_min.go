/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {

    Solutions := []func(*TreeNode) int {
        // BFS_with_set,
        BFS_economic,
    }
    return Solutions[0](root)
}

func BFS_economic(root * TreeNode) int {

    res0 := math.MaxUint32
    res1 := math.MaxUint32

	Q := []*TreeNode{ root }
	for len(Q) > 0 {
		node := Q[0]
        Q = Q[1:]
        n := node.Val
		if n < res0 {
			res1 = res0
			res0 = n
		} else if n != res0 && n < res1 {
			res1 = n
		}

		if node.Left != nil {
			Q = append(Q, node.Left)
		}
		if node.Right != nil {
			Q = append(Q, node.Right)
		}
	}

	if res1 != math.MaxUint32 {
		return res1
	}
	return -1
}

func BFS_with_set(root * TreeNode) int {

    Q := []*TreeNode{ root }
    S := map[int]bool{}
    for len(Q) > 0 {
        node := Q[0]
        Q = Q[1:]
        n := node.Val
        S[n] = true
        if node.Left != nil {
            Q = append(Q, node.Left)
        }
        if node.Right != nil {
            Q = append(Q, node.Right)
        }
    }
    arr := []int{}
    for key, _ := range S {
        arr = append(arr, key)
    }
    if len(arr) < 2 {
        return -1
    }
    sort.Ints(arr)
    return arr[1]
}
