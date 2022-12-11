/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    odd := head
    even := head.Next
    even_head := head.Next
    for odd.Next != nil && even.Next != nil {
        odd.Next = even.Next
        even.Next = odd.Next.Next
        odd = odd.Next
        even = even.Next
    }
    odd.Next = even_head
    return head
}
