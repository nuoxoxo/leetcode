/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    arr := []int {}
    ptr := head
    for ptr != nil {
        arr = append(arr, ptr.Val)
        ptr = ptr.Next
    }
    return make_tree(arr, 0, len(arr) - 1)
}

func    make_tree(arr []int, L int, R int) *TreeNode {
    if L > R {
        return nil
    }
    mid := (R - L) / 2 + L
    node := & TreeNode {Val: arr[mid]}
    node.Left = make_tree(arr, L, mid - 1)
    node.Right = make_tree(arr, mid + 1, R)
    return node
}

