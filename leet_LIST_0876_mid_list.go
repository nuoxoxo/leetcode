/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    size := 0
    node := head
    for node != nil {
        node = node.Next
        size++
    }
    node = head
    size /= 2
    for size > 0 {
        node = node.Next
        size--
    }
    return node
}
