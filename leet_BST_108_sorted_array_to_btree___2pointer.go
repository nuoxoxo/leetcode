/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
    return make_tree(nums, 0, len(nums) - 1)
}

func    make_tree(nums [] int, L int, R int) *TreeNode {
    if L > R {
        return nil
    }
    mid := (R - L) / 2 + L
    node := & TreeNode {
        Val:    nums[mid], 
        Left:   make_tree(nums, L, mid - 1), 
        Right:  make_tree(nums, mid + 1, R),
    }
    return node
}
