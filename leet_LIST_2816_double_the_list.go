/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
    if head.Val > 4 {
        head = & ListNode { Val:0, Next:head }
    }
    node := head
    for node != nil {
        node.Val = (node.Val * 2) % 10
        if node.Next != nil && node.Next.Val > 4 {
            node.Val++
        }
        node = node.Next
    }
    return head
}
