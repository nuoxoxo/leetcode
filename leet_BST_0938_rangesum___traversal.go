func rangeSumBST(root *TreeNode, low int, high int) int {
    var res int
    res = 0
    recur(&res, root, low, high)
    return res
}

func recur(res *int, node *TreeNode, lo int, hi int) {
    if node == nil {
        return
    }
    if lo <= node.Val && node.Val <= hi {
        *res += node.Val
    }
    recur(res, node.Left, lo, hi)
    recur(res, node.Right, lo, hi)
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
